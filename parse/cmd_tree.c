/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:13 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/22 16:55:55 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../signal/minsignal.h"

static t_list	*make_pipelist(t_tree *tree, int *heredoc_count, t_list *envp);
static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree, int *heredoc_count, t_list *envp);
static t_list		*cmd_tree_rd_list(t_list **rd_list, \
					t_tree *tree, int *heredoc_count, t_list *envp);
static t_list		*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree);

int	inorder_cmd_tree(t_tree *tree, t_list *envp, \
	int flag, int *heredoc_count)
{
	t_token		*token;
	t_list		*pipelist;
	int			exit_num;

	pipelist = NULL;
	if (tree == NULL)
		return 0;
	token = tree->token;
	if (tree->left)
	{
		if (!(tree->left->status == LIST && (flag == OR_FALSE || flag == AND_FALSE)))
			exit_num = inorder_cmd_tree(tree->left, envp, flag, heredoc_count);
	}
	if (tree->left && tree->left->status == PIPELINE)
	{
		if ((flag == AND_TRUE || flag == OR_TRUE || flag == START))
		{
			pipelist = make_pipelist(tree->left, heredoc_count, envp);
			extends_env(envp, &pipelist);
			wildcard(&pipelist);
			exit_num = start_process(pipelist, envp);
			free_pipe_list(pipelist);
		}
		else if (flag == OR_FALSE)
			exit_num = 0;
		else if (flag == AND_FALSE)
			exit_num = 1;
	}
	if (tree->status == LIST)
	{
		if (tree->token)
		{
			if (tree->token->type == AND_OPERATOR)
			{
				if (exit_num == 0)
					flag = AND_TRUE;
				else
					flag = AND_FALSE;
			}
			else if (tree->token->type == OR_OPERATOR)
			{
				if (exit_num != 0)
					flag = OR_TRUE;
				else
					flag = OR_FALSE;
			}
		}
	}
	if (tree->right)
		exit_num = inorder_cmd_tree(tree->right, envp, flag, heredoc_count);
	return exit_num;
}

// void	inorder_cmd_tree(t_tree *tree, t_list *envp, \
// 	int flag, int *heredoc_count)
// {
// 	t_token		*token;
// 	t_list		*pipelist;
// 	int			exit_num;

// 	pipelist = NULL;
// 	if (tree == NULL)
// 		return ;
// 	token = tree->token;
// 	if (tree->left)
// 	{
// 		pipelist = make_pipelist(&pipelist, tree->left, heredoc_count, envp);
// 		extends_env(envp, &pipelist);
// 		wildcard(&pipelist);
// 	}
// 	if (flag == AND_TRUE || flag == OR_FALSE || flag == START)
// 	{
// 		exit_num = start_process(pipelist, envp);
// 		free_pipe_list(pipelist);
// 	}
// 	if (token && (token->type == OR_OPERATOR
// 			|| token->type == AND_OPERATOR))
// 	{
// 		flag = divide_flag(token->type, exit_num);
// 		inorder_cmd_tree(tree->right, envp, flag, heredoc_count);
// 	}
// }

// static t_list	*make_pipelist(t_list **pipelist,t_tree *tree, int *heredoc_count, t_list *envp)
// {
// 	t_list	*new_pipelist;

// 	if (!tree)
// 		return (NULL);
// 	if (tree->left)
// 		make_pipelist(pipelist, tree->left, heredoc_count, envp);
// 	if (tree->status == PIPELINE)
// 	{
// 		new_pipelist = ft_lstnew(new_cmd_tree_pipeline(tree->left, heredoc_count, envp));
// 		if (*pipelist)
// 			ft_lstadd_back(pipelist, new_pipelist);
// 		else
// 			*pipelist = new_pipelist;
// 	}
// 	if (tree->right)
// 		make_pipelist(pipelist, tree->left, heredoc_count, envp);
// 	return (*pipelist);
// }


static t_list	*make_pipelist(t_tree *tree, int *heredoc_count, t_list *envp)
{
	t_list	*pipelist;

	if (!tree)
		return (NULL);
	pipelist = ft_lstnew(new_cmd_tree_pipeline(tree->left, heredoc_count, envp));
	if (tree->right)
		pipelist->next = make_pipelist(tree->right, heredoc_count, envp);
	return (pipelist);
}

static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree, int *heredoc_count, t_list *envp)
{
	t_cmd_node	*pipe_node;
	t_list		*rd_list;
	t_list		*cmd_list;

	if (!tree)
		return (NULL);
	rd_list = NULL;
	cmd_list = NULL;
	rd_list = cmd_tree_rd_list(&rd_list, tree, heredoc_count, envp);
	cmd_list = cmd_tree_cmd_list(&cmd_list, tree);
	pipe_node = new_cmd_node(rd_list, cmd_list);
	return (pipe_node);
}

t_list	*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree)
{
	t_list	*new_cmd_list;
	char	*cmd;
	t_token	*token;

	if (!tree)
		return (NULL);
	if (tree->left)
		cmd_tree_cmd_list(cmd_list, tree->left);
	token = tree->token;
	if (token && token->type == WORD)
	{
		cmd = ft_strdup(token->str);
		new_cmd_list = ft_lstnew(cmd);
		if (*cmd_list)
			ft_lstadd_back(cmd_list, new_cmd_list);
		else
			*cmd_list = new_cmd_list;
	}
	if (tree->right)
		cmd_tree_cmd_list(cmd_list, tree->right);
	return (*cmd_list);
}

static t_list	*cmd_tree_rd_list(t_list **rd_list, \
				t_tree *tree, int *heredoc_count, t_list *envp)
{
	t_list		*new_rd_list;
	t_rd_node	*rd_node;
	t_token		*token;
	char		*filename;

	if (!tree)
		return (NULL);
	if (tree->left)
		cmd_tree_rd_list(rd_list, tree->left, heredoc_count, envp);
	token = tree->token;
	if (token && is_redicrtion(token))
	{
		if (token->type == REDIRECT_HEREDOC)
		{
			//signal(SIGINT,SIG_IGN);
			filename = heredoc(tree->redirect->filename, heredoc_count, envp);
			//signalinit();
			token->type = REDIRECT_IN;
			tree->redirect->filename = filename;
			(*heredoc_count)++;
		}
		rd_node = tree->redirect;
		new_rd_list = ft_lstnew(rd_node);
		if (*rd_list)
			ft_lstadd_back(rd_list, new_rd_list);
		else
			*rd_list = new_rd_list;
	}
	if (tree->right)
		cmd_tree_rd_list(rd_list, tree->right, heredoc_count, envp);
	return (*rd_list);
}

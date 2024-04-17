/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:13 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/17 15:15:11 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list		*make_pipelist(t_tree *tree, int *heredoc_count);
static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree, int *heredoc_count);
static t_list		*cmd_tree_rd_list(t_list **rd_list, \
					t_tree *tree, int *heredoc_count);
static t_list		*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree);

void	inorder_cmd_tree(t_tree *tree, t_list *envp, \
	int flag, int *heredoc_count)
{
	t_token		*token;
	t_list		*pipelist;
	int			exit_num;

	pipelist = NULL;
	if (tree == NULL)
		return ;
	token = tree->token;
	if (tree->left)
	{
		pipelist = make_pipelist(tree->left, heredoc_count);
		extends_env(envp, &pipelist);
	}
	if (flag == AND_TRUE || flag == OR_FALSE || flag == START)
		exit_num = start_process(pipelist, envp, heredoc_count);
	if (token && (token->type == OR_OPERATOR
			|| token->type == AND_OPERATOR))
	{
		flag = divide_flag(token->type, exit_num);
		inorder_cmd_tree(tree->right, envp, flag, heredoc_count);
	}
}

static t_list	*make_pipelist(t_tree *tree, int *heredoc_count)
{
	t_list	*pipelist;

	if (!tree)
		return (NULL);
	pipelist = ft_lstnew(new_cmd_tree_pipeline(tree->left, heredoc_count));
	if (tree->right)
		pipelist->next = make_pipelist(tree->right, heredoc_count);
	return (pipelist);
}

static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree, int *heredoc_count)
{
	t_cmd_node	*pipe_node;
	t_list		*rd_list;
	t_list		*cmd_list;
	//char		*filename;

	if (!tree)
		return (NULL);
	rd_list = NULL;
	cmd_list = NULL;
	rd_list = cmd_tree_rd_list(&rd_list, tree, heredoc_count);
	cmd_list = cmd_tree_cmd_list(&cmd_list, tree);
	//printf("%p\n", cmd_list);
	pipe_node = new_cmd_node(rd_list, cmd_list);
	return (pipe_node);
}

static t_list	*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree)
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
				t_tree *tree, int *heredoc_count)
{
	t_list		*new_rd_list;
	t_rd_node	*rd_node;
	t_token		*token;
	char		*filename;

	if (!tree)
		return (NULL);
	if (tree->left)
		cmd_tree_rd_list(rd_list, tree->left, heredoc_count);
	token = tree->token;
	if (token && is_redicrtion(token))
	{
		if (token->type == REDIRECT_HEREDOC)
		{
			filename = heredoc(token->str, heredoc_count);
			token->type = REDIRECT_IN;
			token->str = filename;
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
		cmd_tree_rd_list(rd_list, tree->right, heredoc_count);
	return (*rd_list);
}

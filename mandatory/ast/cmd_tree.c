/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:13 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 11:47:40 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../signal/minsignal.h"

static t_list		*cmd_tree_rd_list(t_list **rd_list, t_tree *tree);
static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree);
static t_list		*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree);

int	inorder_cmd_tree(t_tree *tree, t_list *envp, int flag)
{
	t_token		*token;
	int			exit_num;

	if (tree == NULL)
		return (0);
	token = tree->token;
	if (tree->left && !(tree->left->status == LIST && \
	(flag == OR_FALSE || flag == AND_FALSE)))
		exit_num = inorder_cmd_tree(tree->left, envp, flag);
	if (tree->left && tree->left->status == PIPELINE)
		tree_status_pipeline(tree, flag, envp, &exit_num);
	if (tree->status == LIST)
		tree_status_list(tree, &flag, exit_num);
	if (tree->right)
		exit_num = inorder_cmd_tree(tree->right, envp, flag);
	return (exit_num);
}

t_list	*make_pipelist(t_tree *tree)
{
	t_list	*pipelist;

	if (!tree)
		return (NULL);
	pipelist = ft_lstnew(new_cmd_tree_pipeline(tree->left));
	if (tree->right)
		pipelist->next = make_pipelist(tree->right);
	return (pipelist);
}

static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree)
{
	t_cmd_node	*pipe_node;
	t_list		*rd_list;
	t_list		*cmd_list;

	if (!tree)
		return (NULL);
	rd_list = NULL;
	cmd_list = NULL;
	rd_list = cmd_tree_rd_list(&rd_list, tree);
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

static t_list	*cmd_tree_rd_list(t_list **rd_list, t_tree *tree)
{
	t_list		*new_rd_list;
	t_rd_node	*rd_node;
	t_token		*token;

	if (!tree)
		return (NULL);
	if (tree->left)
		cmd_tree_rd_list(rd_list, tree->left);
	token = tree->token;
	if (token && is_redicrtion(token))
	{
		rd_node = tree->redirect;
		rd_node = new_rd_node(rd_node->rd_type, ft_strdup(rd_node->filename));
		new_rd_list = ft_lstnew(rd_node);
		if (*rd_list)
			ft_lstadd_back(rd_list, new_rd_list);
		else
			*rd_list = new_rd_list;
	}
	if (tree->right)
		cmd_tree_rd_list(rd_list, tree->right);
	return (*rd_list);
}

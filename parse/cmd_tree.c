/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:56:13 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/08 12:51:37 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_list		*make_pipelist(t_tree *tree);
static t_cmd_node	*new_cmd_tree_pipeline(t_tree *tree);
static t_list		*cmd_tree_rd_list(t_list **rd_list, t_tree *tree);
static t_list		*cmd_tree_cmd_list(t_list **cmd_list, t_tree *tree);

void	inorder_cmd_tree(t_tree *tree)
{
	t_token		*token;
	t_list		*pipelist;

	if (tree == NULL)
		return ;
	token = tree->token;
	if (tree->left)
		pipelist = make_pipelist(tree->left);
	if (token && (token->type == OR_OPERATOR
			|| token->type == AND_OPERATOR))
		inorder_cmd_tree(tree->right);
}

static t_list	*make_pipelist(t_tree *tree)
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
		cmd = token->str;
		new_cmd_list = ft_lstnew(cmd);
		ft_lstadd_back(cmd_list, new_cmd_list);
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
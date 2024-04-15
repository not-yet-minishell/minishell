/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:12:37 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/15 16:12:25 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	clear_tree(t_tree *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		clear_tree(tree->left);
	if (tree->right)
		clear_tree(tree->right);
	if (tree->token)
		ft_del_token_node(tree->token);
	if (tree->redirect)
	{
		if (tree->redirect->filename)
			free(tree->redirect->filename);
		free(tree->redirect);
	}
	if (tree)
		free(tree);
}

void	tree_parser_error(t_list **list, t_tree *tree)
{
	(void)tree;
	clear_tree(tree);
	ft_lstclear(list, (void *) ft_del_token_node);
}

t_tree	*ft_tree_new(t_token *token, int status)
{
	t_tree	*tree;

	tree = ft_malloc(sizeof(t_tree));
	tree->token = token;
	tree->status = status;
	tree->redirect = NULL;
	tree->left = NULL;
	tree->right = NULL;
	return (tree);
}

int	is_redicrtion(t_token *token)
{
	if (token->type == REDIRECT_APPEND
		|| token->type == REDIRECT_HEREDOC
		|| token->type == REDIRECT_IN
		|| token->type == REDIRECT_OUT)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:12:37 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/02 14:20:19 by soljeong         ###   ########.fr       */
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
	if (tree)
		free(tree);
}

void	tree_parser_error(t_list **list, t_tree *tree)
{
	ft_lstclear(list, (void *) ft_del_token_node);
	clear_tree(tree);
}

t_tree	*ft_tree_new(t_token *token)
{
	t_tree	*tree;

	tree = malloc(sizeof(t_tree));
	tree->token = token;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:12:37 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/02 14:16:03 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_tree	*syntax_cmd(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	tree = ft_tree_new(NULL);
	tree->left = syntax_simple_cmd(list);
	if (!(tree->left))
	{
		tree_parser_error(list, tree);
		return (0);
	}
	if ((*list) == NULL)
		return (tree);
	token = (t_token *)(*list)->content;
	if (token->type == WORD || is_redicrtion(token))
		tree->right = syntax_cmd(list);
	return (tree);
}

t_tree	*syntax_simple_cmd(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	if ((*list) == NULL)
		return (0);
	token = (t_token *)(*list)->content;
	if (token->type == WORD)
	{
		tree = ft_tree_new(NULL);
		tree->token = token;
		list_shift(list);
		return (tree);
	}
	else
		return (syntax_redirection(list));
}

t_tree	*syntax_redirection(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	token = (t_token *)(*list)->content;
	tree = ft_tree_new(NULL);
	if (is_redicrtion(token) && (*list)->next)
	{
		tree->token = token;
		list_shift(list);
		token = (t_token *)(*list)->content;
		if (token->type == WORD)
		{
			tree->right = ft_tree_new(token);
			list_shift(list);
			return (tree);
		}
	}
	tree_parser_error(list, tree);
	return (0);
}

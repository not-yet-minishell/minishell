/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:40:49 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 10:11:00 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../minishell.h"

t_tree	*parse_tree(t_list **list)
{
	t_tree	*tree;

	ft_del_token_node((*list)->content);
	list_shift(list);
	if (!*list)
		return (0);
	tree = syntax_list(list);
	if (*list || tree == NULL)
	{
		parse_error();
		tree_parser_error(list, tree);
		return (0);
	}
	return (tree);
}

t_tree	*syntax_list(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	tree = ft_tree_new(NULL, LIST);
	tree->left = syntax_sublist(list);
	if (tree->left == NULL)
	{
		tree_parser_error(list, tree);
		return (0);
	}
	if (*list == NULL)
		return (tree);
	token = (t_token *)(*list)->content;
	if (token->type == AND_OPERATOR || token->type == OR_OPERATOR)
	{
		tree->token = token;
		list_shift(list);
		tree->right = syntax_list(list);
		if (tree->right == NULL)
		{
			tree_parser_error(list, tree);
			return (0);
		}
	}
	return (tree);
}

t_tree	*syntax_paren(t_list **list, t_token *token)
{
	t_tree	*tree;

	ft_del_token_node(token);
	list_shift(list);
	tree = syntax_list(list);
	if (!tree)
		return (0);
	if (*list == NULL)
	{
		tree_parser_error(list, tree);
		return (0);
	}
	token = (t_token *)(*list)->content;
	if (token->type == R_PAREN)
	{
		ft_del_token_node(token);
		list_shift(list);
		return (tree);
	}
	return (0);
}

t_tree	*syntax_sublist(t_list **list)
{
	t_token	*token;

	if (*list == NULL)
		return (NULL);
	token = (t_token *)(*list)->content;
	if (token->type == L_PAREN)
		return (syntax_paren(list, token));
	else
		return (syntax_pipeline(list));
}

t_tree	*syntax_pipeline(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	tree = ft_tree_new(NULL, PIPELINE);
	tree->left = syntax_cmd(list);
	if (tree->left == NULL)
	{
		tree_parser_error(list, tree);
		return (0);
	}
	if (*list == NULL)
		return (tree);
	token = (t_token *)(*list)->content;
	if (token->type == PIPE)
	{
		tree->token = token;
		list_shift(list);
		tree->right = syntax_pipeline(list);
		if (!(tree->right))
			return (0);
	}
	return (tree);
}

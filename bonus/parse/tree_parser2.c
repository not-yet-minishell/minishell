/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:12:37 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/24 19:00:10 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../ast/cmd_tree.h"

static t_tree	*syntax_simple_cmd(t_list **list);
static t_tree	*syntax_redirection(t_list **list);

t_tree	*syntax_cmd(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	tree = ft_tree_new(NULL, CMD);
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
	{
		tree->right = syntax_cmd(list);
		if (tree->right == NULL)
		{
			tree_parser_error(list, tree);
			return (0);
		}
	}
	return (tree);
}

static t_tree	*syntax_simple_cmd(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	if ((*list) == NULL)
		return (0);
	token = (t_token *)(*list)->content;
	if (token->type == WORD)
	{
		tree = ft_tree_new(NULL, SMPCMD);
		tree->token = token;
		list_shift(list);
		return (tree);
	}
	else
		return (syntax_redirection(list));
}

static t_tree	*syntax_redirection(t_list **list)
{
	t_token		*token;
	t_tree		*tree;
	t_rd_node	*rd_node;
	int			rd_type;

	token = (t_token *)(*list)->content;
	tree = ft_tree_new(NULL, RD);
	if (is_redicrtion(token) && (*list)->next)
	{
		tree->token = token;
		rd_type = token->type;
		list_shift(list);
		token = (t_token *)(*list)->content;
		if (token->type == WORD)
		{
			rd_node = new_rd_node(rd_type, token->str);
			tree->redirect = rd_node;
			list_shift(list);
			free(token);
			return (tree);
		}
	}
	tree_parser_error(list, tree);
	return (0);
}

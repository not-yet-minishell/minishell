/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:40:49 by soljeong          #+#    #+#             */
/*   Updated: 2024/03/26 20:23:04 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

// 지금 종단 점에서 에러나고있음...

t_tree *parse_tree(t_list **list);
t_tree *ft_tree_new(t_token *token);
t_tree *syntax_list(t_list **list);
t_tree *syntax_sublist(t_list **list);
t_tree *syntax_pipeline(t_list **list);
t_tree *syntax_cmd(t_list **list);
t_tree *syntax_simple_cmd(t_list **list);
t_tree *syntax_redirection(t_list **list);



void curr_list_print(t_list *list)
{
	t_token *token;

	token = (t_token *)list->content;
	printf("str :%s\n", token->str);
}

t_tree *parse_tree(t_list **list)
{
	*list = (*list)->next;
	if (!*list)
		return (0);
	return (syntax_list(list));
}

t_tree *ft_tree_new(t_token *token)
{
	t_tree *tree;

	tree = malloc(sizeof(t_tree));
	tree->token = token;
	return tree;
}

t_tree *syntax_list(t_list **list)
{
	t_token	*token;
	t_tree	*tree;

	// 일단 tree new 해야함
	tree = ft_tree_new(NULL);
	tree->left = syntax_sublist(list);
	if (tree->left == NULL)
		parse_error();
	if (*list == NULL)
		return (tree);
	token = (t_token *)(*list)->content;
	if (token->type == AND_OPERATOR || token->type == OR_OPERATOR)
	{
		tree->token = token;
		*list = (*list)->next;
		tree->right = syntax_list(list);
		if (tree->right == NULL)
			parse_error();
	}
	return (tree);
}

t_tree *syntax_sublist(t_list **list)
{
	t_token *token;
	t_tree	*tree;

	if (*list == NULL)
		return (NULL);
	token = (t_token *)(*list)->content;
	if (token->type == L_PAREN)
	{
		*list = (*list)->next;
		tree = syntax_list(list);
		if (!tree)
			parse_error();
		token = (t_token *)(*list)->content;
		curr_list_print(*list);
		if (token->type == R_PAREN)
		{
			*list = (*list)->next;
			return (tree);
		}
		else
		{
			parse_error();
			return (0);
			//error
		}
			//error
	}
	else
		return (syntax_pipeline(list));
}

t_tree *syntax_pipeline(t_list **list)
{
	t_token *token;
	t_tree	*tree;

	tree = ft_tree_new(NULL);
	tree->left = syntax_cmd(list);
	if (!(tree->left))
		parse_error();
	if (*list == NULL)
		return tree;
	token = (t_token *)(*list)->content;
	if (token->type == PIPE)
	{
		curr_list_print(*list);
		tree->token = token;
		*list = (*list)->next;
		tree->right = syntax_pipeline(list);
		if (!(tree->right))
			parse_error();
	}
	return tree;
}

t_tree *syntax_cmd(t_list **list)
{
	t_token *token;
	t_tree	*tree;

	tree = ft_tree_new(NULL);
	tree->left = syntax_simple_cmd(list);
	if (!(tree->left))
		parse_error();
	if ((*list) == NULL)
		return tree;
	token = (t_token *)(*list)->content;
	if (token->type == WORD || token->type == REDIRECT_IN
	|| token->type == REDIRECT_OUT || token->type == REDIRECT_APPEND
	|| token->type == REDIRECT_HEREDOC)
		tree->right = syntax_cmd(list);
	return tree;
}

t_tree *syntax_simple_cmd(t_list **list)
{
	t_token *token;
	t_tree	*tree;

	if ((*list) == NULL)
		return NULL;
	token = (t_token *)(*list)->content;
	tree = ft_tree_new(NULL);
	if (token->type == WORD)
	{
		tree->token = token;
		*list = (*list)->next;
		return (tree);
	}
	else
		return (syntax_redirection(list));
}

t_tree *syntax_redirection(t_list **list)
{
	t_token	*token;
	t_tree	*tree;
	t_tree	*subtree;

	if (*list == NULL)
		parse_error();
	token = (t_token *)(*list)->content;
	tree = ft_tree_new(NULL);
	if (token->type == REDIRECT_APPEND
	|| token->type == REDIRECT_HEREDOC
	|| token->type == REDIRECT_IN
	|| token->type == REDIRECT_OUT)
	{
		tree->token = token;
		*list = (*list)->next;
		if (*list == NULL)
			parse_error();
		token = (t_token *)(*list)->content;
		if (token->type == WORD)
		{
			subtree = ft_tree_new(token);
			curr_list_print(*list);
			(*list) = (*list)->next;
			return (tree);
		}
		else
			parse_error();
	}
	else
		parse_error();
		return (0);
}
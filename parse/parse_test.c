/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:10:51 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/02 14:17:59 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "parse_test.h"

void	tree_inorder_print(t_tree *tree)
{
	if (tree == NULL)
		return ;
	if (tree->left != NULL)
	{
		tree_inorder_print(tree->left);
	}
	if (tree->token != NULL && tree->token->str != NULL)
		printf("tree str: %s\n", tree->token->str);
	if (tree->right != NULL)
	{
		tree_inorder_print(tree->right);
	}
}

void	curr_list_print(t_list *list)
{
	t_token	*token;

	if (!list)
	{
		printf("no!!\n");
		return ;
	}
	token = (t_token *)list->content;
	printf("str :%s\n", token->str);
}

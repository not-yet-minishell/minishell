/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:10:51 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/11 17:39:35 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

	if (list == NULL)
	{
		printf("no!!\n");
		return ;
	}
	printf("몇번이나 들어와...\n");
	token = list->content;
	print_node(token);
	if (token == NULL)
		return ;
	//printf("str: %p\n", token->str);
	//printf("type: %d\n", token->type);
	//printf("str :%s\n", token->str);
}

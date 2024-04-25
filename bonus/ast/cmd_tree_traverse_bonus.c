/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tree_traverse_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:52:24 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 13:43:24 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_tree_bonus.h"

void	tree_status_list(t_tree *tree, int *flag, int exit_num)
{
	if (tree->token)
	{
		if (tree->token->type == AND_OPERATOR)
		{
			if (exit_num == 0)
				*flag = AND_TRUE;
			else
				*flag = AND_FALSE;
		}
		else if (tree->token->type == OR_OPERATOR)
		{
			if (exit_num != 0)
				*flag = OR_TRUE;
			else
				*flag = OR_FALSE;
		}
	}
}

void	tree_status_pipeline(t_tree *tree, int flag, \
t_list *envp, int *exit_num)
{
	t_list	*pipelist;

	if ((flag == AND_TRUE || flag == OR_TRUE || flag == START))
	{
		pipelist = make_pipelist(tree->left);
		extends_env(envp, &pipelist);
		wildcard(&pipelist);
		*exit_num = start_process(pipelist, envp);
		free_pipe_list(pipelist);
	}
	else if (flag == OR_FALSE)
		*exit_num = 0;
	else if (flag == AND_FALSE)
		*exit_num = 1;
}

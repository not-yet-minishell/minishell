/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:24:32 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 12:54:57 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*parse(char *line, t_list *env_list)
{
	t_list	*token_head;
	t_tree	*tree;
	// int		i;

	// i = 0;
	// while (line[i] == ' ')
	token_head = tokenizer(line);
	if (!token_head)
	{
		((t_builtin *)env_list->content)->exit_num = 258;
		free(line);
		return (NULL);
	}
	tree = parse_tree(&token_head);
	if (!tree)
	{
		((t_builtin *)env_list->content)->exit_num = 258;
		free(line);
		return (NULL);
	}
	return (tree);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:24:32 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:17:27 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*parse(char *line, t_list *env_list)
{
	t_list	*token_head;
	t_tree	*tree;

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

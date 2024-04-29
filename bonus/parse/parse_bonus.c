/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:24:32 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 14:24:12 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"

static void	*parsing_error_exit_free(t_list *env_list, char *line, \
int exit_num);

t_tree	*parse(char *line, t_list *env_list)
{
	t_list	*token_head;
	t_tree	*tree;
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	token_head = tokenizer(line);
	if (!token_head)
		return (parsing_error_exit_free(env_list, line, 258));
	tree = parse_tree(&token_head);
	if (!tree)
		return (parsing_error_exit_free(env_list, line, 258));
	return (tree);
}

static void	*parsing_error_exit_free(t_list *env_list, char *line, int exit_num)
{
	((t_builtin *)env_list->content)->exit_num = exit_num;
	free(line);
	return (NULL);
}

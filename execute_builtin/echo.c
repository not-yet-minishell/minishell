/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:07 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/08 19:02:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static int	check_flag(char **cmd, int *flag);
static void	check_env_and_print(char *str, t_list *env_list);

void	echo(char **cmd, t_list *env_list)
{
	int		idx;
	int		flag;

	flag = 1;
	idx = check_flag(cmd, &flag);
	while (cmd[idx] != NULL)
	{
		check_env_and_print(cmd[idx], env_list);
		if (cmd[idx + 1] != NULL)
			ft_printf(1, " ");
		idx++;
	}
	if (flag == FALSE)
		ft_printf(1, "\n");
}

static int	check_flag(char **cmd, int *flag)
{
	int	idx;

	idx = 0;
	if (*cmd[0] != '-')
		*flag = -1;
	while (cmd[idx] != NULL)
	{
		if (*cmd[idx] != '-')
			break ;
		else
		{
			cmd[idx]++;
			while (*cmd[idx] != '\0')
			{
				if (*cmd[idx] != 'n')
				{
					*flag = -1;
					break ;
				}
				cmd[idx]++;
			}
		}
		idx++;
	}
	return (idx);
}

static void	check_env_and_print(char *str, t_list *env_list)
{
	t_env	*content;

	if (*str != '$')
		ft_printf(1, "%s", str);
	str++;
	env_list = env_list->next;
	while (env_list != NULL)
	{
		content = env_list->content;
		if (ft_strncmp(*str, content->key, ft_strlen(*str) + 1) == 0)
		{
			ft_printf(1, "%s", str);
			return ;
		}
	}
	return ;
}

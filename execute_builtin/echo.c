/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:07 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/18 10:33:28 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin.h"

static int	check_flag(char **cmd, int *flag);
//static void	check_env_and_print(char *str, t_list *env_list);

void	ft_echo(char **cmd, t_list *env_list)
{
	int		idx;
	int		flag;

	idx = 0;
	flag = check_flag(cmd, &idx);
	while (cmd[idx] != NULL)
	{
		ft_printf(1, "%s", cmd[idx]);
		//check_env_and_print(cmd[idx], env_list);
		if (cmd[idx + 1] != NULL)
			ft_printf(1, " ");
		idx++;
	}
	if (flag == FALSE)
		ft_printf(1, "\n");
	change_exit_number(0, env_list);
}

static int	check_flag(char **cmd, int *idx)
{
	int	ret_flag;
	int	flag_idx;

	ret_flag = FALSE;
	while (*cmd != NULL)
	{
		flag_idx = 0;
		if (*cmd[flag_idx] != '-')
			return (ret_flag);
		flag_idx++;
		while (cmd[*idx][flag_idx] != '\0')
		{
			if (cmd[*idx][flag_idx] != 'n')
				return (ret_flag);
			flag_idx++;
		}
		if ((*idx) == 0)
			ret_flag = TRUE;
		(*idx)++;
	}
	return (ret_flag);
}

// static void	check_env_and_print(char *str, t_list *env_list)
// {
// 	t_env	*content;

// 	if (*str != '$')
// 	{
// 		ft_printf(1, "%s", str);
// 		return ;
// 	}
// 	str++;
// 	env_list = env_list->next;
// 	while (env_list != NULL)
// 	{
// 		content = env_list->content;
// 		if (ft_strncmp(str, content->key, ft_strlen(str) + 1) == 0)
// 		{
// 			ft_printf(1, "%s", str);
// 			return ;
// 		}
// 	}
// 	return ;
// }

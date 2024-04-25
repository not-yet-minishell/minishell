/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 20:24:51 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 12:50:21 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute_builtin_bonus.h"

static int			isnum(char *content);
static long long	ft_atoll(char *str, t_list *env_list);
static int			check_long(char *str, t_list *env_list);
static int			is_sign(char *content);

void	ft_exit(char **cmd, t_list *env_list)
{
	long long	exit_num;

	if (cmd[1] == NULL)
		exit(((t_builtin *)env_list->content)->exit_num);
	ft_putendl_fd(*cmd, STDOUT_FILENO);
	if (isnum(cmd[1]) == FALSE || is_sign(cmd[1]) == TRUE)
	{
		exit_num = 255;
		change_exit_number(exit_num, env_list);
		error_handler(*cmd, cmd[1], "numeric argument required\n");
		exit(exit_num);
	}
	if (cmd[2] != NULL)
	{
		error_handler(*cmd, NULL, "too many arguments\n");
		change_exit_number(1, env_list);
		return ;
	}
	exit_num = ft_atoll(cmd[1], env_list);
	change_exit_number(exit_num, env_list);
	exit(exit_num % 256);
}

static int	is_sign(char *content)
{
	if (content[0] == '+' || content[0] == '-')
	{
		if (content[1] == '\0')
			return (TRUE);
	}
	return (FALSE);
}

static int	isnum(char *content)
{
	if (*content == '\0')
		return (FALSE);
	if (*content == '-' || *content == '+')
		content ++;
	while (*content)
	{
		if (*content >= '0' && *content <= '9')
			content++;
		else
			return (FALSE);
	}
	return (TRUE);
}

static long long	ft_atoll(char *str, t_list *env_list)
{
	int			idx;
	long long	num;
	int			flag;

	idx = 0;
	num = 0;
	flag = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			flag *= -1;
		str++;
	}
	while (*str == '0')
		str++;
	if (flag == -1 && ft_strncmp("9223372036854775808", str, 19) == 0)
		return ((flag) * 9223372036854775808ULL);
	if (check_long(str, env_list) != 1)
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + *str - 48;
		str ++;
	}
	return (flag * num);
}

static int	check_long(char *str, t_list *env_list)
{
	int	len;

	len = ft_strlen(str);
	if (len > 19)
	{
		change_exit_number(255, env_list);
		error_handler("exit", str, "numeric argument required\n");
		exit(255);
	}
	if (len < 19)
		return (1);
	if (ft_strncmp("9223372036854775807", str, 19) < 0)
	{
		change_exit_number(255, env_list);
		error_handler("exit", str, "numeric argument required\n");
		exit(255);
	}
	return (1);
}

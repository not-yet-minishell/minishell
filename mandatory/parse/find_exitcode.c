/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_exitcode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:09:02 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/23 11:16:47 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_exit_code(t_list *env)
{
	t_builtin	*content;
	char		*str;

	content = env->content;
	str = ft_itoa((content->exit_num));
	return (str);
}

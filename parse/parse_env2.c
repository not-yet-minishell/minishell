/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:35:36 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/23 11:51:40 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_env.h"

void	add_oldpwd(t_list *env)
{
	t_env	*content;
	t_list	*env_node;

	content = ft_malloc(sizeof(t_env));
	content->key = "OLDPWD";
	content->value = NULL;
	env_node = ft_lstnew(content);
	ft_lstadd_back(&env, env_node);
}

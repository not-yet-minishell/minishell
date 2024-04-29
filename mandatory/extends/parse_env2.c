/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 18:35:36 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 15:26:30 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extends.h"

void	add_head_oldpwd(t_list **env)
{
	t_env	*content;
	t_list	*env_node;

	content = ft_malloc(sizeof(t_env));
	content->key = ft_strdup("OLDPWD");
	content->value = NULL;
	env_node = ft_lstnew(content);
	ft_lstadd_back(env, env_node);
}

void	find_and_add_path(t_list **env)
{
	t_list	*pre;
	t_list	*current;
	t_list	*new_node;
	t_env	*content;

	pre = *env;
	current = *env;
	while (current != NULL)
	{
		if (ft_strncmp("PATH", ((t_env *)current->content)->key, 5) == 0)
			return ;
		pre = current;
		current = current->next;
	}
	content = ft_malloc(sizeof(t_env));
	content->key = ft_strdup("PATH");
	content->value = ft_strdup("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.");
	new_node = ft_lstnew(content);
	if (*env == NULL)
		*env = new_node;
	else
		pre->next = new_node;
}

void	find_and_add_pwd(t_list *env)
{
	t_list	*pre;
	t_list	*current;
	t_list	*new_node;
	t_env	*content;
	char	*pwd;

	pre = env;
	current = env;
	while (current != NULL)
	{
		if (ft_strncmp("PWD", ((t_env *)current->content)->key, 4) == 0)
			return ;
		pre = current;
		current = current->next;
	}
	content = ft_malloc(sizeof(t_env));
	content->key = ft_strdup("PWD");
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
		pwd = ft_strdup(".");
	content->value = pwd;
	new_node = ft_lstnew(content);
	pre->next = new_node;
}

void	find_and_add_oldpwd(t_list *env)
{
	t_list	*pre;
	t_list	*current;
	t_list	*new_node;
	t_env	*content;

	pre = env;
	current = env;
	while (current != NULL)
	{
		if (ft_strncmp("OLDPWD", ((t_env *)current->content)->key, 7) == 0)
			return ;
		pre = current;
		current = current->next;
	}
	content = ft_malloc(sizeof(t_env));
	content->key = ft_strdup("OLDPWD");
	content->value = NULL;
	new_node = ft_lstnew(content);
	pre->next = new_node;
}

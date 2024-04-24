/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 02:00:55 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/24 10:44:20 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDS_H
# define EXTENDS_H

# include "../minishell.h"

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_builtin
{
	char	*pwd;
	int		exit_num;
}	t_builtin;

void	extends_env(t_list *env, t_list **cmd_list);
t_list	*parse_env(char *env[]);
t_list	*select_sort(t_list *env_list);
void	add_oldpwd(t_list *env);
char	*extends_find_env_firstnum(char *str, int *i, int *env_start);
void	extdns_find_exit_code(int *i, char **value, t_list *env);
char	*extends_find_env(char *str, int *i, t_list *env);
t_list	*parse_env(char *env[]);
char	*change_str(char *str, t_list *env);
char	*change_str_heredoc(char *str, int *flag);
void	str_temp_join(char **new, char *temp);
void	str_divide_join(char **new, char *str, int start, int i);
char	*remove_dobulequote(char *str, int *i, t_list *env);
char	*remove_singlequote(char *str, int *i);
t_list	*select_sort(t_list *env_list);
char	*chage_env_key_to_value(char *str, t_list *env);

#endif
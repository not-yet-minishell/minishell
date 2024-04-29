/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extends_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:51:27 by yeoshin           #+#    #+#             */
/*   Updated: 2024/04/25 15:28:35 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXTENDS_BONUS_H
# define EXTENDS_BONUS_H

# include "../minishell_bonus.h"

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
void	add_oldpwd(t_list **env);
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
void	find_and_add_path(t_list **env);
void	find_and_add_pwd(t_list *env);
void	find_and_add_oldpwd(t_list *env);

#endif
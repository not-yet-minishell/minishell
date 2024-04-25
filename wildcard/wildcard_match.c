/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_match.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soljeong <soljeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 10:45:01 by soljeong          #+#    #+#             */
/*   Updated: 2024/04/25 10:04:54 by soljeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	match_point(char *str, int *sIdx, char *pattern, int *pIdx);
static int	match_str_pattern(char *str, int *sIdx, char *pattern, int *pIdx);
static void	idxplus(int *s_idx, int *p_idx);

int	is_match(char *str, char *pattern)
{
	int	s_idx;
	int	p_idx;

	s_idx = 0;
	p_idx = 0;
	if (match_point(str, &s_idx, pattern, &p_idx) == 0)
		return (0);
	if (match_str_pattern(str, &s_idx, pattern, &p_idx) == 0)
		return (0);
	while (pattern[p_idx] && pattern[p_idx] == '\12')
		p_idx++;
	if (p_idx == (int)ft_strlen(pattern))
		return (1);
	return (0);
}

int	match_point(char *str, int *s_idx, char *pattern, int *p_idx)
{
	if (str[*s_idx] == '.')
	{
		if (str[*s_idx] == pattern[*p_idx])
		{
			(*s_idx)++;
			(*p_idx)++;
		}
		else
			return (0);
	}
	return (1);
}

int	match_str_pattern(char *str, int *s_idx, char *pattern, int *p_idx)
{
	int	stemp_idx;
	int	star_idx;

	stemp_idx = -1;
	star_idx = -1;
	while (*s_idx < (int)ft_strlen(str))
	{
		if (str[*s_idx] && pattern[*p_idx] && str[*s_idx] == pattern[*p_idx])
			idxplus(s_idx, p_idx);
		else if (pattern[*p_idx] && pattern[*p_idx] == '\12')
		{
			star_idx = (*p_idx);
			stemp_idx = (*s_idx);
			(*p_idx)++;
		}
		else if (star_idx != -1)
		{
			(*p_idx) = star_idx + 1;
			(*s_idx) = ++stemp_idx;
		}
		else
			return (0);
	}
	return (1);
}

void	idxplus(int *s_idx, int *p_idx)
{
	(*s_idx)++;
	(*p_idx)++;
}

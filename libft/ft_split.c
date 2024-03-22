/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:55:58 by yeoshin           #+#    #+#             */
/*   Updated: 2023/11/05 21:50:04 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_word(char *str, char sep)
{
	int	idx_str;
	int	flag_sep;
	int	count;

	flag_sep = 1;
	idx_str = 0;
	count = 0;
	while (str[idx_str])
	{
		if (flag_sep == 1 && str[idx_str] != sep)
		{
			count += 1;
			flag_sep = 0;
		}
		else if (str[idx_str] == sep)
			flag_sep = 1;
		idx_str ++;
	}
	return (count);
}

static	char	*put_str(char *temp, char const *str, int count, int idx_start)
{
	int	i;

	i = 0;
	while (i < count)
	{
		temp[i] = str[idx_start + i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static	char	*find_str(char *temp, char const *str, char sep, int *idx)
{
	int	idx_start;
	int	flag_sep;
	int	count;

	flag_sep = 1;
	count = 0;
	while (str[*idx])
	{
		if (flag_sep == 1 && str[*idx] != sep)
		{
			count += 1;
			idx_start = *idx;
			flag_sep = 0;
		}
		else if (flag_sep == 0 && str[*idx] != sep)
			count += 1;
		else if (flag_sep == 0 && str[*idx] == sep)
			break ;
		(*idx)++;
	}
	temp = (char *)malloc(count + 1);
	if (temp == NULL)
		return (NULL);
	temp = put_str(temp, str, count, idx_start);
	return (temp);
}

static void	*ft_free(char **string, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		free(string[i]);
		i ++;
	}
	free(string);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**ret_str;
	int		idx;
	int		count;
	int		len;
	char	*temp;

	idx = 0;
	len = 0;
	if (str == NULL)
		return (NULL);
	count = count_word((char *)str, c);
	ret_str = (char **)malloc(sizeof(char *) * (count + 1));
	if (ret_str == NULL)
		return (NULL);
	while (len < count)
	{
		temp = find_str(temp, str, c, &idx);
		if (temp == NULL)
			return (ft_free(ret_str, len));
		ret_str[len ++] = temp;
	}
	ret_str[len] = NULL;
	return (ret_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeoshin <yeoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 21:21:43 by yeoshin           #+#    #+#             */
/*   Updated: 2024/03/04 17:22:20 by yeoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(int fd, const char *str, ...);
int		before_p(char *str, int *return_len, int fd);
int		after_p(char *str, va_list print_list, int *return_len, int fd);
int		print_itos(int n, int *return_len, int fd);
int		print_xtos(unsigned int num, int *return_len, char flag, int fd);
int		write_hex_x(unsigned int num, int *return_len, int fd);
int		write_hex_bigx(unsigned int num, int *return_len, int fd);
int		print_utos(unsigned int num, int *return_len, int fd);
int		print_ptos(unsigned long long pointer, int *return_len, int fd);
int		print_c(char c, int *return_len, int fd);
int		print_s(void *s, int *return_len, int fd);

#endif

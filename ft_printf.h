/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:03:04 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/06 23:49:29 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/inc/libft.h"

# define CHAR 'c'
# define STR 's'
# define PTR 'p'
# define NUM1 'd'
# define NUM2 'i'
# define UN_INT 'u'
# define HEX1 'x'
# define HEX2 'X'

typedef struct	s_arg
{
	char	flag;
	int		width;
	int		prec;
	char	type;
}				t_arg;

char			ft_setflag(const char *str, int *i);
int				ft_setprec(const char *str, int *i, va_list ap);
int				ft_setwidth(va_list ap, t_arg *format, const char *str, int *i);
size_t			print_space(t_arg *format, size_t len);
size_t			print_arg(va_list ap, t_arg *format, size_t count);
int				print_char(char c);
int				ft_printf(const char *str, ...);
size_t			print_in_format(unsigned int n, t_arg *format, size_t len, char *base);
size_t			ft_putnbr_base(unsigned int n, size_t len, char *base);
size_t			print_c(char c, t_arg *format, size_t count);
size_t			print_d(int n, t_arg *format, size_t count);
size_t			print_s(char *s, t_arg *format, size_t count);
size_t			print_ux(unsigned int n, t_arg *format, size_t count,
														char *base);
size_t			print_p(unsigned long int n, t_arg *format, size_t count,
														char *base);

#endif

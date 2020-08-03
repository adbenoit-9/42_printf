/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:03:04 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/11 19:26:08 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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

int				ft_type(char c);
int				ft_atoi(const char *str);
int				ft_free(void *tab, int ret);
char			*ft_nb(const char *str, int *i);
char			ft_flag(const char *str, int *i);
int				ft_precision(const char *str, int *i, va_list ap);
int				ft_width(va_list ap, t_arg *arg, const char *str, int *i);
int				ft_complete(const char *str, va_list ap, t_arg *arg, int *i);
size_t			ft_putspace(t_arg *arg, size_t len);
size_t			ft_putarg(va_list ap, t_arg *arg, size_t count);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar_count(char c, size_t *count);
size_t			ft_putchar_arg(char c, t_arg *arg, size_t count);
void			ft_putstr_fd(char *s, int fd);
void			ft_putstr_count(char *s, size_t len, size_t *count);
size_t			ft_putstr_arg(char *s, t_arg *arg, size_t count);
size_t			ft_strlen(const char *s);
int				ft_printf(const char *str, ...);
size_t			ft_putall(unsigned int n, t_arg *arg, size_t len, char *base);
size_t			ft_arglen_base(unsigned int n, size_t baselen);
size_t			ft_putnbr_base(unsigned int n, size_t len, char *base);
size_t			ft_putnbr_arg(unsigned int n, t_arg *arg, size_t count,
														char *base);
size_t			ft_arglen(int n);
size_t			ft_putnbr(int n, t_arg *arg, size_t count);
size_t			ft_ptrlen(unsigned long int n, size_t baselen);
size_t			ft_putptr(unsigned long int n, size_t len, char *base);
size_t			ft_putptr_arg(unsigned long int n, t_arg *arg, size_t count,
														char *base);
unsigned int	ft_sign(int n);

#endif

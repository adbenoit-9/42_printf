/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:25:11 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/07 17:41:54 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putstr_count(char *s, size_t len, size_t *count)
{
	if (s)
		write(1, s, len);
	(*count) += len;
}

size_t	ft_putstr_arg(char *s, t_arg *arg, size_t count)
{
	int len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (arg && arg->flag != '-')
		count += ft_putspace(arg, len);
	if (arg && arg->prec >= 0 && arg->prec < len)
	{
		if (s)
			write(1, s, arg->prec);
		else
			write(1, "(null)", arg->prec);
		count += arg->prec;
	}
	else
	{
		if (s)
			ft_putstr_count(s, len, &count);
		else
			ft_putstr_count("(null)", len, &count);
	}
	count += ft_putspace(arg, len);
	return (count);
}

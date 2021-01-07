/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:25:11 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 01:25:24 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_str(char *s)
{
	int	len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		return (len);
	}
	len = 6;
	write(1, "(null)", len);
	return (len);
}

size_t		print_s(char *s, t_arg *format, size_t count)
{
	int len;

	if (!s)
		len = 6;
	else
		len = ft_strlen(s);
	if (format && format->flag != '-')
		count += print_space(format, len);
	if (format && format->prec >= 0 && format->prec < len)
	{
		if (s)
			write(1, s, format->prec);
		else
			write(1, "(null)", format->prec);
		count += format->prec;
	}
	else
		count += print_str(s);
	count += print_space(format, len);
	return (count);
}

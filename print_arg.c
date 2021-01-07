/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:07:18 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 00:39:41 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_space(t_arg *format, size_t len)
{
	size_t	count;
	char	ret;

	count = 0;
	ret = format->flag;
	if (format->flag == '-')
		ret = ' ';
	if ((format->type == STR && format->prec > (int)len) || format->type == CHAR ||
													format->type == '%')
		format->prec = -1;
	while (format->width > format->prec && (format->width > (int)len ||
						(format->type == STR && format->prec > -1)))
	{
		ft_putchar_fd(ret, 1);
		format->width--;
		count++;
	}
	return (count);
}

size_t	print_arg(va_list ap, t_arg *format, size_t count)
{
	static char	*base_x = "0123456789abcdef";
	static char	*base_ux = "0123456789ABCDEF";

	if (format->type == NUM1 || format->type == NUM2)
		count = print_d(va_arg(ap, int), format, count);
	else if (format->type == UN_INT)
		count = print_ux(va_arg(ap, unsigned int), format, count, "0123456789");
	else if (format->type == HEX1)
		count = print_ux(va_arg(ap, unsigned int), format, count, base_x);
	else if (format->type == HEX2)
		count = print_ux(va_arg(ap, unsigned int), format, count, base_ux);
	else if (format->type == CHAR)
		count = print_c((unsigned char)va_arg(ap, int), format, count);
	else if (format->type == STR)
		count = print_s(va_arg(ap, char *), format, count);
	else if (format->type == PTR)
		count = print_p(va_arg(ap, unsigned long int), format, count, base_x);
	else if (format->type == '%')
		count = print_c('%', format, count);
	return (count);
}

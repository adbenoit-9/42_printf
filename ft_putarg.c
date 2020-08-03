/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 14:07:18 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/11 18:14:15 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putspace(t_arg *arg, size_t len)
{
	size_t	count;
	char	ret;

	count = 0;
	ret = arg->flag;
	if (arg->flag == '-')
		ret = ' ';
	if ((arg->type == STR && arg->prec > (int)len) || arg->type == CHAR ||
													arg->type == '%')
		arg->prec = -1;
	while (arg->width > arg->prec && (arg->width > (int)len ||
						(arg->type == STR && arg->prec > -1)))
	{
		ft_putchar_fd(ret, 1);
		arg->width--;
		count++;
	}
	return (count);
}

size_t	ft_putarg(va_list ap, t_arg *arg, size_t count)
{
	if (arg->type == NUM1 || arg->type == NUM2)
		count = ft_putnbr(va_arg(ap, int), arg, count);
	if (arg->type == UN_INT)
		count = ft_putnbr_arg(va_arg(ap, unsigned int), arg, count,
											"0123456789");
	if (arg->type == HEX1)
		count = ft_putnbr_arg(va_arg(ap, unsigned int), arg, count,
											"0123456789abcdef");
	if (arg->type == HEX2)
		count = ft_putnbr_arg(va_arg(ap, unsigned int), arg, count,
											"0123456789ABCDEF");
	if (arg->type == CHAR)
		count = ft_putchar_arg((unsigned char)va_arg(ap, int), arg, count);
	if (arg->type == STR)
		count = ft_putstr_arg(va_arg(ap, char *), arg, count);
	if (arg->type == PTR)
		count = ft_putptr_arg(va_arg(ap, unsigned long int), arg, count,
											"0123456789abcdef");
	if (arg->type == '%')
		count = ft_putchar_arg('%', arg, count);
	return (count);
}

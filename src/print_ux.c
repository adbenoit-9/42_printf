/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:31:39 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 01:25:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_in_format(unsigned int n, t_arg *format, size_t len, char *base)
{
	size_t	count;
	int		k;

	count = 0;
	while (format->flag == '0' && format->width > (int)len && format->prec < 0)
	{
		count += print_char('0');
		format->width--;
	}
	k = format->prec + 1;
	while (--k > (int)len)
		count += print_char('0');
	count += ft_putnbr_base(n, len, base);
	return (count);
}

size_t	ft_putnbr_base(unsigned int n, size_t len, char *base)
{
	size_t	baselen;

	if (n == 0)
		ft_putchar_fd('0', 1);
	baselen = ft_strlen(base);
	if (n > 0)
	{
		if (n / baselen != 0)
			ft_putnbr_base(n / baselen, len, base);
		ft_putchar_fd(base[n % baselen], 1);
	}
	return (len);
}

static size_t	ft_arglen_base(unsigned int n, size_t baselen)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / baselen;
		len++;
	}
	return (len);
}

size_t	print_ux(unsigned int n, t_arg *format, size_t count, char *base)
{
	size_t	len;
	size_t	baselen;

	baselen = ft_strlen(base);
	len = ft_arglen_base(n, baselen);
	if (format->flag != '-' && (format->prec > -1 || format->flag != '0'))
	{
		format->flag = ' ';
		count += print_space(format, len);
	}
	if (n == 0 && format->prec == 0)
	{
		if (format->width > 0)
			count += print_char(' ');
	}
	else
		count += print_in_format(n, format, len, base);
	count += print_space(format, len);
	return (count);
}

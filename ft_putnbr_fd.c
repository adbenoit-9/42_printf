/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:35:36 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/11 19:23:27 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t			ft_arglen(int n)
{
	unsigned int	num;
	size_t			len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		num = -n;
	}
	else
		num = n;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

unsigned int	ft_sign(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		num = n * -1;
	}
	else
		num = n;
	return (num);
}

size_t			ft_putnbr(int n, t_arg *arg, size_t count)
{
	unsigned int	num;
	size_t			len;

	len = ft_arglen(n);
	if (n < 0 && arg->prec > 0)
		arg->prec++;
	if (arg && arg->flag != '-' && (arg->prec > -1 || arg->flag != '0'))
	{
		arg->flag = ' ';
		count += ft_putspace(arg, len);
	}
	if (n == 0 && arg->prec == 0)
	{
		if (arg->width > 0)
			ft_putchar_count(' ', &count);
	}
	else
	{
		num = ft_sign(n);
		count += ft_putall(num, arg, len, "0123456789");
	}
	count += ft_putspace(arg, len);
	return (count);
}

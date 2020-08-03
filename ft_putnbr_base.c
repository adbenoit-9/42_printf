/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:31:39 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/11 19:13:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putall(unsigned int n, t_arg *arg, size_t len, char *base)
{
	size_t	count;
	int		k;

	count = 0;
	while (arg->flag == '0' && arg->width > (int)len && arg->prec < 0)
	{
		ft_putchar_count('0', &count);
		arg->width--;
	}
	k = arg->prec + 1;
	while (--k > (int)len)
		ft_putchar_count('0', &count);
	count += ft_putnbr_base(n, len, base);
	return (count);
}

size_t	ft_arglen_base(unsigned int n, size_t baselen)
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

size_t	ft_putnbr_arg(unsigned int n, t_arg *arg, size_t count, char *base)
{
	size_t	len;
	size_t	baselen;

	baselen = ft_strlen(base);
	len = ft_arglen_base(n, baselen);
	if (arg->flag != '-' && (arg->prec > -1 || arg->flag != '0'))
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
		count += ft_putall(n, arg, len, base);
	count += ft_putspace(arg, len);
	return (count);
}

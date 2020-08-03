/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:18:59 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/07 17:33:50 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_ptrlen(unsigned long int n, size_t baselen)
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

size_t	ft_putptr(unsigned long int n, size_t len, char *base)
{
	size_t	baselen;

	if (n == 0)
		ft_putchar_fd('0', 1);
	baselen = ft_strlen(base);
	if (n > 0)
	{
		if (n / baselen != 0)
			ft_putptr(n / baselen, len, base);
		ft_putchar_fd(base[n % baselen], 1);
	}
	return (len);
}

size_t	ft_putptr_arg(unsigned long int n, t_arg *arg, size_t count, char *base)
{
	size_t	len;
	size_t	baselen;
	int		k;

	baselen = ft_strlen(base);
	len = ft_ptrlen(n, baselen) + 2;
	if (arg->flag == ' ')
		count += ft_putspace(arg, len);
	if (n == 0 && arg->prec == 0)
		;
	else
	{
		while (arg->flag == '0' && arg->width > (int)len && arg->prec == -1)
		{
			ft_putchar_count('0', &count);
			arg->width--;
		}
		k = arg->prec + 1;
		while (--k > (int)len)
			ft_putchar_count('0', &count);
		ft_putstr_fd("0x", 1);
		count += ft_putptr(n, len, base);
	}
	count += ft_putspace(arg, len);
	return (count);
}

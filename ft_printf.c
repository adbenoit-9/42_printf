/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 10:47:00 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/13 16:05:45 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_type(char c)
{
	if (c == NUM1 || c == NUM2 || c == HEX1 || c == HEX2 || c == STR || c == PTR
									|| c == CHAR || c == UN_INT || c == '%')
		return (1);
	return (0);
}

int		ft_complete(const char *str, va_list ap, t_arg *arg, int *i)
{
	if (str[*i] && str[*i + 1] && str[*i] == '%')
	{
		(*i)++;
		arg->flag = ft_flag(str, i);
		if ((arg->width = ft_width(ap, arg, str, i)) == -2)
			return (-1);
		if ((arg->prec = ft_precision(str, i, ap)) == -2)
			return (-1);
		arg->type = str[*i];
	}
	return (0);
}

int		ft_free(void *tab, int ret)
{
	free(tab);
	return (ret);
}

int		ft_printf(const char *str, ...)
{
	int		i;
	size_t	count;
	t_arg	arg;
	va_list	ap;

	va_start(ap, str);
	i = -1;
	count = 0;
	while (str[++i])
	{
		if (str[i + 1] && str[i] == '%')
		{
			if (ft_complete(str, ap, &arg, &i) == -1)
				return (-1);
			if (!ft_type(arg.type))
				return (-1);
			count = ft_putarg(ap, &arg, count);
		}
		else
			ft_putchar_count(str[i], &count);
	}
	va_end(ap);
	return (count);
}

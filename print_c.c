/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:17:19 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 01:25:47 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	print_c(char c, t_arg *format, size_t count)
{
	if (format && format->flag != '-')
		count += print_space(format, 1);
	count += print_char(c);
	count += print_space(format, 1);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:17:19 by adbenoit          #+#    #+#             */
/*   Updated: 2019/12/09 15:25:46 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar_count(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

size_t	ft_putchar_arg(char c, t_arg *arg, size_t count)
{
	if (arg && arg->flag != '-')
		count += ft_putspace(arg, 1);
	ft_putchar_count(c, &count);
	count += ft_putspace(arg, 1);
	return (count);
}

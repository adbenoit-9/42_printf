/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:48:24 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 02:06:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t ret, size_t size)
{
	char	*mem;

	if (!(mem = (char *)malloc(ret * size)))
		return (0);
	ft_bzero(mem, ret * size);
	return ((void *)mem);
}

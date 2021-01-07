/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:46:09 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 02:06:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int *ret1, int *ret2, char const *s1,
												char const *set)
{
	int	j;
	int	i;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[*ret1] == set[j])
				++(*ret1);
			if (s1[*ret2] == set[j])
				--(*ret2);
			++j;
		}
		++i;
	}
	if ((*ret2 - *ret1 + 1) < 0)
		return (0);
	return (*ret2 - *ret1 + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	int		ret1;
	int		ret2;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	ret1 = 0;
	ret2 = ft_strlen(s1) - 1;
	len = ft_len(&ret1, &ret2, s1, set);
	i = 0;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (ret1 <= ret2)
	{
		str[i] = s1[ret1];
		++i;
		++ret1;
	}
	str[i] = 0;
	return (str);
}

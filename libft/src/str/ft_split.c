/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbenoit <adbenoit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 16:49:10 by adbenoit          #+#    #+#             */
/*   Updated: 2021/01/07 02:06:25 by adbenoit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_retrow(char const *s, char c)
{
	size_t	ret;
	size_t	i;

	ret = 0;
	i = 0;
	if (s[0] != c && s[0] != 0)
	{
		++ret;
		++i;
	}
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			++ret;
		++i;
	}
	return (ret);
}

static size_t	ft_size(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		++size;
		++i;
	}
	return (size);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	k;

	if (s == NULL)
		return (NULL);
	i = 0;
	k = -1;
	if (!(tab = malloc(sizeof(char*) * (ft_retrow(s, c) + 1))))
		return (0);
	while (++k < ft_retrow(s, c))
	{
		while (s[i] == c && s[i])
			++i;
		if (!(tab[k] = malloc(sizeof(char) * (ft_size(s, c, i) + 1))))
			return (ft_freetab(tab));
		j = -1;
		--i;
		while (s[++i] != c && s[i])
			tab[k][++j] = s[i];
		tab[k][j + 1] = 0;
	}
	tab[k] = 0;
	return (tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:45:46 by alebross          #+#    #+#             */
/*   Updated: 2019/11/14 14:54:02 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_strcpy(char *dest, char const *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static unsigned int		count_strs(char const *str, char c)
{
	unsigned int	i;
	unsigned int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
}

static unsigned int		nextstrlen(char const *str, char c, unsigned int i)
{
	unsigned int	size;

	size = 0;
	while (str[size + i] != c && str[i + size])
		size++;
	return (size + 1);
}

static char				**ft_split2(char const *str, char c, char **split
, unsigned int nb_strs)
{
	unsigned int	i[3];

	i[0] = 0;
	i[1] = 0;
	while (str[i[0]] && i[1] < nb_strs)
	{
		while (str[i[0]] == c && str[i[0]])
			i[0]++;
		if (!(split[i[1]] = malloc(sizeof(char) * (nextstrlen(str, c, i[0])))))
			return (0);
		i[2] = 0;
		while (str[i[0]] != c && str[i[0]])
		{
			split[i[1]][i[2]] = str[i[0]];
			i[0]++;
			i[2]++;
		}
		split[i[1]][i[2]] = '\0';
		i[1]++;
	}
	split[i[1]] = 0;
	return (split);
}

char					**ft_split(char const *str, char c)
{
	char			**split;
	unsigned int	i;
	unsigned int	nb_strs;

	i = 0;
	if (!str)
		return (NULL);
	if (!c)
	{
		split = malloc(sizeof(*split) * 2);
		if (!(split[0] = malloc(sizeof(char) * ft_strlen(str))))
			return (NULL);
		split[0] = ft_strcpy(split[0], str);
		split[1] = NULL;
	}
	if (!(split = malloc(sizeof(*split) * (count_strs(str, c) + 1))))
		return (NULL);
	nb_strs = count_strs(str, c);
	split = ft_split2(str, c, split, nb_strs);
	return (split);
}

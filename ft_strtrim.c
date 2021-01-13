/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:00:49 by alebross          #+#    #+#             */
/*   Updated: 2019/11/12 17:26:42 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	s[size] = '\0';
	return (s);
}

static int	ft_isset(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return ((char*)s1);
	k = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strnew(0));
	while (ft_isset(s1[k - j], set))
		j++;
	if (!(k - j))
		return (ft_strnew(0));
	k -= j + i - 1;
	return (ft_substr(s1, i, k));
}

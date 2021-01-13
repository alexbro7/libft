/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 01:16:33 by alebross          #+#    #+#             */
/*   Updated: 2019/11/13 15:03:58 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	s[size] = '\0';
	return (s);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;

	dest = ft_strnew(len);
	if (!s || !dest)
		return (NULL);
	if (start >= len)
	{
		dest[0] = '\0';
		return (dest);
	}
	i = 0;
	while (i < (unsigned int)len && s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

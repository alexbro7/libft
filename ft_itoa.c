/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:33:07 by alebross          #+#    #+#             */
/*   Updated: 2019/11/12 17:29:15 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char				*ft_strnew(size_t size)
{
	char	*s;

	if (!(s = (char *)ft_calloc(size + 1, sizeof(char))))
		return (NULL);
	s[size] = '\0';
	return (s);
}

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

static unsigned int		ft_nblen(int n)
{
	unsigned int	res;

	res = 1;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n / 10)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char				*ft_itoa2(char *s, int n)
{
	int	i;
	int	x;

	i = 0;
	x = 1;
	if (n < 0)
	{
		s[i] = '-';
		n *= -1;
		i++;
	}
	while (n / x > 9)
		x *= 10;
	while (x)
	{
		s[i] = (n / x) + '0';
		n %= x;
		x /= 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

char					*ft_itoa(int n)
{
	char	*s;

	if (n == -2147483648)
	{
		s = ft_strcpy(ft_strnew(11), "-2147483648");
		return (s);
	}
	if (!(s = malloc(sizeof(char) * (ft_nblen(n) + 1))))
		return (NULL);
	return (ft_itoa2(s, n));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:19:49 by alebross          #+#    #+#             */
/*   Updated: 2019/11/17 16:11:43 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*to_find == '\0')
		return ((char*)str);
	while (str[i] && ft_strlen(str) >= ft_strlen(to_find) && i < (int)len)
	{
		if (str[i] == to_find[j])
		{
			while (str[i] == to_find[j] && i < (int)len)
			{
				if (to_find[j + 1] == '\0')
					return ((char*)&str[i - j]);
				i++;
				j++;
			}
			i = i - j;
		}
		j = 0;
		i++;
	}
	return (0);
}

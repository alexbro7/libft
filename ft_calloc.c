/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:19:02 by alebross          #+#    #+#             */
/*   Updated: 2019/11/12 18:37:01 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*res;
	size_t		i;

	i = size * nmemb;
	if (!(res = malloc(i)))
		return (NULL);
	if (i == 0)
		return (res);
	while (i)
	{
		--i;
		*((unsigned char*)res + i) = 0;
	}
	return (res);
}

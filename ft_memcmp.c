/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alebross <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:35:43 by alebross          #+#    #+#             */
/*   Updated: 2019/11/12 16:51:39 by alebross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *ptr_1;
	const unsigned char *ptr_2;

	ptr_1 = (const unsigned char*)s1;
	ptr_2 = (const unsigned char*)s2;
	while (n)
	{
		if (*ptr_1 != *ptr_2)
			return ((int)(*ptr_1 - *ptr_2));
		n--;
		ptr_1++;
		ptr_2++;
	}
	return (0);
}

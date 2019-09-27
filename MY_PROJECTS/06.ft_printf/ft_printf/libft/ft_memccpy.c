/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:40:33 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 16:37:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *d, const void *s, int ch, size_t c)
{
	size_t	index;

	index = 0;
	if (d == (void *)s)
		return ((void *)s);
	while (index < c)
	{
		((unsigned char *)d)[index] = ((unsigned char *)s)[index];
		if (((unsigned char *)s)[index] == (unsigned char)ch)
			return (((unsigned char *)d) + index + 1);
		index++;
	}
	return (NULL);
}

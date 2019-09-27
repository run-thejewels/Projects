/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:42:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/02 23:34:19 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *source, size_t count)
{
	size_t	index;

	index = 0;
	if (dest == source)
		return ((void *)source);
	if (source < dest)
	{
		while (count--)
			((char *)dest)[count] = ((char *)source)[count];
	}
	else
	{
		while (index < count)
		{
			((char *)dest)[index] = ((char *)source)[index];
			index++;
		}
	}
	return (dest);
}

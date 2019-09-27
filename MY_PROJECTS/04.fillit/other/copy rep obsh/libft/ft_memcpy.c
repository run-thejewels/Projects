/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:15:12 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/27 17:31:46 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *source, size_t n)
{
	char *a;
	char *b;

	a = (char *)dst;
	b = (char *)source;
	while (n != 0)
	{
		*a++ = *b++;
		n--;
	}
	return (dst);
}

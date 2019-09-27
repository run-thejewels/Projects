/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 12:08:23 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/25 14:41:41 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst - src > 0)
	{
		i = len;
		while (i != 0)
		{
			--i;
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

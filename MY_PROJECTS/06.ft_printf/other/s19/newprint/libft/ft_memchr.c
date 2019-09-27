/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:41:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/28 19:06:06 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *buffer, int ch, size_t count)
{
	size_t			index;
	unsigned char	che;
	unsigned char	*buf;

	index = 0;
	che = (unsigned char)ch;
	buf = (unsigned char *)buffer;
	while (index < count)
	{
		if (buf[index] == che)
			return (buf + index);
		index++;
	}
	return (NULL);
}

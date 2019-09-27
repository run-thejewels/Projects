/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:05:55 by waddam            #+#    #+#             */
/*   Updated: 2018/12/01 20:10:58 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*temp_d;
	unsigned char	*temp_s;

	i = 0;
	temp_d = dst;
	temp_s = (unsigned char *)src;
	while (i < n)
	{
		temp_d[i] = temp_s[i];
		if (temp_d[i] == (unsigned char)c)
		{
			return (&temp_d[i + 1]);
		}
		i++;
	}
	return (NULL);
}

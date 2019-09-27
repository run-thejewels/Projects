/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 12:03:55 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/29 16:19:33 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		src_len;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = size - dst_len - 1;
	while (src_len > 0 && src[i] && i < src_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (size < dst_len)
		return (size + ft_strlen(src));
	else
		return (dst_len + ft_strlen(src));
}

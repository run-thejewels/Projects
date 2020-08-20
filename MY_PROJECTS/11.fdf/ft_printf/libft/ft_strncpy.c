/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:59:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:26:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dest, const char *source, size_t count)
{
	size_t	end;
	size_t	size;

	size = ft_strlen(source);
	if (size < count)
	{
		end = count - size;
		dest = ft_memcpy(dest, source, size);
		while (end)
		{
			dest[size - 1 + end] = '\0';
			end--;
		}
		return (dest);
	}
	dest = ft_memcpy(dest, source, count);
	return (dest);
}

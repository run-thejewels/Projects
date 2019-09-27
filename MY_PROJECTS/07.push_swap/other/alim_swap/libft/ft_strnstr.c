/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:41:55 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/23 20:24:54 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (haystack[i] == needle[i] && haystack[i] == '\0')
		return (&((char *)haystack)[i]);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (i + j < len && needle[j] && haystack[i + j] &&
				haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return (&((char *)haystack)[i]);
		i++;
	}
	return (NULL);
}

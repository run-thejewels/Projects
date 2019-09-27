/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:12:22 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/29 17:42:31 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	const char	*s;

	if (!*to_find)
		return ((char *)str);
	while (*str && n > 0)
	{
		if (*str == *to_find)
		{
			s = str;
			while (*str++ == *to_find++)
			{
				if (*to_find == 0 && n >= (unsigned int)str - (unsigned int)s)
					return ((char *)s);
			}
			to_find -= str - s;
			str = s;
		}
		n--;
		str++;
	}
	return (NULL);
}

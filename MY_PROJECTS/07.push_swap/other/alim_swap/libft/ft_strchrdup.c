/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:43:20 by rymuller          #+#    #+#             */
/*   Updated: 2018/12/20 16:54:36 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	charlen(char const *s, char c)
{
	size_t		i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		return (i);
	}
	return (0);
}

char			*ft_strchrdup(const char *s1, char c)
{
	char		*dst;
	size_t		len;

	len = charlen(s1, c);
	if (!(dst = (char *)malloc(sizeof(*s1) * (len + 1))))
		return (NULL);
	ft_strncpy(dst, s1, len);
	dst[len] = '\0';
	return (dst);
}

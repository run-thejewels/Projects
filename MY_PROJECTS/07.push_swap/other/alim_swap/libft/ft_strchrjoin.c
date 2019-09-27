/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:08:49 by rymuller          #+#    #+#             */
/*   Updated: 2018/12/10 12:23:00 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	charlen(char const *s, char c)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != '\0' && s[i] != c)
			i++;
		return (i);
	}
	return (0);
}

char			*ft_strchrjoin(char const *s1, char const *s2, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + charlen(s2, c);
		if (!(res = (char *)malloc(len + 1)))
			return (NULL);
		i = -1;
		while (s1[++i])
			res[i] = s1[i];
		j = 0;
		while (s2[j] && s2[j] != c)
		{
			res[i + j] = s2[j];
			j++;
		}
		res[i + j] = '\0';
		return (res);
	}
	return (NULL);
}

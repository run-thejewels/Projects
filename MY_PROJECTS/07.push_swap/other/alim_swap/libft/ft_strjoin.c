/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:44:55 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/26 15:42:37 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*res;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(res = (char *)malloc(len + 1)))
			return (NULL);
		i = -1;
		while (s1[++i])
			res[i] = s1[i];
		j = -1;
		while (s2[++j])
			res[i + j] = s2[j];
		res[i + j] = '\0';
		return (res);
	}
	return (NULL);
}

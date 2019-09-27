/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:51:53 by rymuller          #+#    #+#             */
/*   Updated: 2018/12/07 21:35:19 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*mal;

	if (s != NULL)
	{
		if (!(mal = (char *)malloc(len + 1)))
			return (NULL);
		i = 0;
		while (i < len)
		{
			mal[i] = s[start + i];
			i++;
		}
		mal[i] = '\0';
		return (mal);
	}
	return (NULL);
}

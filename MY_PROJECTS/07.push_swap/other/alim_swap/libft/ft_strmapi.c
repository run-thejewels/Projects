/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 19:54:15 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/29 20:33:06 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*mal;

	if (s != NULL || f != NULL)
	{
		if (!(mal = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		i = 0;
		while (s[i])
		{
			mal[i] = f(i, s[i]);
			i++;
		}
		mal[i] = '\0';
		return (mal);
	}
	return (NULL);
}

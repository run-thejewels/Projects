/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:06:38 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/20 12:58:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	size_t	i;

	i = 0;
	if (f == NULL || s == NULL ||
		!(a = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	else
	{
		while (i < ft_strlen(s))
		{
			a[i] = f(i, s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}

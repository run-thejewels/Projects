/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 19:32:16 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/24 14:53:01 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			a[i] = f(s[i]);
			i++;
		}
		a[i] = '\0';
		return (a);
	}
	return (NULL);
}

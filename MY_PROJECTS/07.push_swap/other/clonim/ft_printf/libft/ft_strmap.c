/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:57:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:00:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*result;
	size_t	index;
	size_t	size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (size + 1 <= size)
		return (NULL);
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	index = 0;
	ft_memcpy(result, s, size);
	while (s[index])
	{
		result[index] = f(s[index]);
		index++;
	}
	result[size] = '\0';
	return (result);
}

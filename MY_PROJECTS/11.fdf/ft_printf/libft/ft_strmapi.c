/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 08:54:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:02:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	index;
	size_t			size;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	if (size + 1 <= size || !(result = (char *)malloc(size + 1)))
		return (NULL);
	index = 0;
	ft_memcpy(result, s, size);
	while (s[index])
	{
		result[index] = f(index, s[index]);
		index++;
	}
	result[size] = '\0';
	return (result);
}

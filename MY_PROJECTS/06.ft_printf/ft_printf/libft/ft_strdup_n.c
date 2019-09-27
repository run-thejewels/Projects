/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 22:55:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:02:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup_n(const char *src, size_t n)
{
	char	*result;
	size_t	size;

	size = ft_strlen_safe(src);
	if (size > n)
		size = n;
	if (!src || (size + 1 <= size) || !(result = (char *)malloc(size + 1)))
		return (NULL);
	result = ft_memcpy(result, src, size);
	result[size] = '\0';
	return (result);
}

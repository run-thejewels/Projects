/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:55:18 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:00:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*result;
	size_t	size;

	if (!src)
		return (NULL);
	size = ft_strlen(src);
	if ((size + 1 <= size) || !(result = (char *)malloc(size + 1)))
		return (NULL);
	result = ft_memcpy(result, src, size + 1);
	return (result);
}

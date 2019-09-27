/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:53:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:02:06 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *str1, const char *str2)
{
	size_t size;

	size = ft_strlen(str2);
	if (size + 1 <= size)
		return (NULL);
	str1 = ft_memcpy(str1, str2, size + 1);
	return (str1);
}

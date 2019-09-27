/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:57:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/04 20:49:50 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *str1, const char *str2, size_t num)
{
	size_t	len;
	size_t	len2;
	size_t	index;
	size_t	index2;

	len = ft_strlen(str1);
	len2 = ft_strlen(str2);
	index = 0;
	index2 = 0;
	if (num <= len)
		return (len2 + num);
	while (str1[index2] && index2 < num - 1)
		index2++;
	while (str2[index] && index2 < num - 1)
	{
		str1[index2] = str2[index];
		index2++;
		index++;
	}
	str1[index2] = '\0';
	return (len + len2);
}

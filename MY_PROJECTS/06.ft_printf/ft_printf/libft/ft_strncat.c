/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:58:17 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 20:54:06 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *str1, const char *str2, size_t num)
{
	size_t	len;
	size_t	index;

	len = ft_strlen(str1);
	index = 0;
	while (str2[index] && index != num)
	{
		str1[len] = str2[index];
		len++;
		index++;
	}
	str1[len] = '\0';
	return (str1);
}

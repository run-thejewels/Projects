/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:58:40 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/28 21:49:12 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2, size_t num)
{
	size_t			index;
	unsigned char	*s1;
	unsigned char	*s2;

	index = 0;
	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	if (!str1 || str2)
		return (0);
	while ((s1[index] || s2[index]) && (index != num))
	{
		if (s1[index] != s2[index])
			return ((int)(s1[index] - s2[index]));
		index++;
	}
	return (0);
}

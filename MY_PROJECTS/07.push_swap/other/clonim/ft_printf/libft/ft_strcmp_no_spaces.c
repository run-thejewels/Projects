/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_no_spaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:51:40 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 20:57:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp_no_spaces(const char *str1, const char *str2)
{
	size_t	index1;
	size_t	index2;

	index1 = 0;
	index2 = 0;
	if (!str1 || !str2)
		return (0);
	while ((str1[index1] || str2[index2]))
	{
		while (ft_isspace(str1[index1]))
			index1++;
		while (ft_isspace(str2[index2]))
			index2++;
		if (str1[index1] != str2[index2])
		{
			return ((int)((unsigned char)str1[index1] - \
			(unsigned char)str2[index2]));
		}
		index1++;
		index2++;
	}
	return (0);
}

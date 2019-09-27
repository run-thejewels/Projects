/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:53:01 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/04 20:52:00 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *str1, const char *str2)
{
	size_t	index;

	index = 0;
	if (!str1 || !str2)
		return (0);
	while ((str1[index] || str2[index]))
	{
		if (str1[index] != str2[index])
		{
			return ((int)((unsigned char)str1[index] - \
			(unsigned char)str2[index]));
		}
		index++;
	}
	return (0);
}

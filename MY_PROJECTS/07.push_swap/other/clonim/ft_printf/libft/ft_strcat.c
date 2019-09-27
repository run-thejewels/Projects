/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:43:28 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 18:12:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *str1, const char *str2)
{
	int len;
	int index;

	len = (int)ft_strlen(str1);
	index = 0;
	while (str2[index] != '\0')
	{
		str1[len] = str2[index];
		len++;
		index++;
	}
	str1[len] = '\0';
	return (str1);
}

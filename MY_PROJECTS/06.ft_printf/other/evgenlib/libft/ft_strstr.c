/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:05:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/08 20:51:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str1, const char *str2)
{
	size_t	index;
	size_t	complite_indicate;
	char	*temp;

	complite_indicate = ft_strlen(str2);
	temp = (char *)str1;
	if (!*str2)
		return (temp);
	while (*temp && *str2)
	{
		index = 0;
		while (temp[index] && str2[index])
		{
			if (temp[index] == str2[index])
				index++;
			else
				break ;
			if (index == complite_indicate)
				return (temp);
		}
		temp++;
	}
	return (NULL);
}

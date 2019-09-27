/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:59:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/08 20:50:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	index;
	char	*temp;

	temp = (char *)str1;
	if (!*str2)
		return (temp);
	while (*temp && len)
	{
		index = 0;
		while (temp[index] && str2[index] && (len - index))
		{
			if (temp[index] == str2[index])
				index++;
			else
				break ;
			if (index == ft_strlen(str2))
				return (temp);
		}
		len--;
		temp++;
	}
	return (NULL);
}

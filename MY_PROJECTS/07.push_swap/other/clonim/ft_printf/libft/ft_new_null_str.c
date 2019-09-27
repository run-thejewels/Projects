/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_null_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 06:31:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/17 22:42:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_new_null_str(size_t size)
{
	char	*result;
	size_t	index;

	if (!size)
		return (NULL);
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	index = 0;
	result[size] = '\0';
	while (size)
	{
		result[index] = '0';
		index++;
		size--;
	}
	return (result);
}

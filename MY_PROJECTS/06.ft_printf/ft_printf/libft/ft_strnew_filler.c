/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:14:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/27 23:30:44 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_filler(size_t size, char filler)
{
	char	*result;

	if (size + 1 > size)
	{
		if (!(result = (char *)malloc(size + 1)))
			return (NULL);
		ft_memset(result, (int)filler, size);
		result[size] = '\0';
		return (result);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:59:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/10 22:05:36 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*result;

	if (size + 1 > size)
	{
		if (!(result = (char *)malloc(size + 1)))
			return (NULL);
		ft_bzero(result, size + 1);
		return (result);
	}
	return (NULL);
}

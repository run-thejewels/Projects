/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:40:09 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 16:32:51 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*result;

	if (!size)
		return (NULL);
	if (!(result = (void *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_bzero(result, size);
	return (result);
}

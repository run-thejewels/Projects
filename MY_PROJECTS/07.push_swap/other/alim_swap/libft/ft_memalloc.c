/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 18:11:23 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/25 18:19:27 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		((unsigned char *)mem)[i++] = 0;
	return (mem);
}

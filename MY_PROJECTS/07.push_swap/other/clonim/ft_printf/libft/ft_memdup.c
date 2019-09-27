/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 00:18:17 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/05 00:01:11 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(void *mem, size_t size)
{
	void	*result;

	if (!mem || !size)
		return (NULL);
	if (!(result = malloc(size)))
		return (NULL);
	ft_memcpy(result, mem, size);
	return (result);
}

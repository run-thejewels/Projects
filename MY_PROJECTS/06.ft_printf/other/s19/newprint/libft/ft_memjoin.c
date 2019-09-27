/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 00:14:27 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/05 00:00:14 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin(void *mem_1, size_t size_1, void *mem_2, size_t size_2)
{
	void	*result;

	if ((!size_1 && !size_2) || (!mem_1 && !mem_2) \
	|| size_1 + size_2 < size_1 || size_1 + size_2 < size_2)
		return (NULL);
	if (!mem_1 || !size_1)
		return (ft_memdup(mem_2, size_2));
	if (!mem_2 || !size_2)
		return (ft_memdup(mem_1, size_1));
	if (!(result = malloc(size_1 + size_2)))
		return (NULL);
	ft_memcpy(result, mem_1, size_1);
	ft_memcpy(ft_jump(result, size_1), mem_2, size_2);
	return (result);
}

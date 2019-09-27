/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin_free_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 22:22:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/16 22:22:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memjoin_free_1(void *mem_1, \
	size_t size_1, void *mem_2, size_t size_2)
{
	void *result;

	result = ft_memjoin(mem_1, size_1, mem_2, size_2);
	free(mem_1);
	return (result);
}

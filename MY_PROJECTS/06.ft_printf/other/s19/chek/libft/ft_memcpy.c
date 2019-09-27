/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:41:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 16:43:16 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destptr, const void *srcptr, size_t num)
{
	if (destptr == (void *)srcptr)
		return ((void *)srcptr);
	while (num)
	{
		((char *)destptr)[num - 1] = ((char *)srcptr)[num - 1];
		num--;
	}
	return (destptr);
}

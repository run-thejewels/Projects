/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_safe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:35:33 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/20 19:39:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_safe(void *destptr, const void *srcptr, size_t num)
{
	if (destptr == (void *)srcptr)
		return ((void *)srcptr);
	if (!destptr || !srcptr)
		return (NULL);
	while (num)
	{
		((char *)destptr)[num - 1] = ((char *)srcptr)[num - 1];
		num--;
	}
	return (destptr);
}

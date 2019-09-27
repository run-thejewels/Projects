/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:55:35 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/01 16:28:18 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*a;

	a = (unsigned char*)memptr;
	if (num == 0)
		return (memptr);
	while (num--)
	{
		*a = (unsigned char)val;
		if (num)
			a++;
	}
	return (memptr);
}

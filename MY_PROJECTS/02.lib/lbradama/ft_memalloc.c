/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:56:51 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/19 13:07:47 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*a;

	if (size < 1024)
	{
		if (!(a = (void*)malloc(sizeof(void) * size)))
			return (NULL);
		return (ft_memset(a, 0, size));
	}
	return (NULL);
}

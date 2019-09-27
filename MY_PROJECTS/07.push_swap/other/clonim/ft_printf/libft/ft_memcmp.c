/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:41:21 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 16:41:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *m1, const void *m2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)m1)[i] != ((unsigned char *)m2)[i])
			return (((unsigned char *)m1)[i] - ((unsigned char *)m2)[i]);
		i++;
	}
	return (0);
}

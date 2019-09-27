/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:49:35 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/20 14:01:06 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *in, int val, size_t n)
{
	unsigned char	*a;

	a = (unsigned char *)in;
	if (n == 0)
	{
		a = NULL;
		return (a);
	}
	while (n--)
	{
		if (*a == (unsigned char)val)
			return (a);
		if (n)
			a++;
	}
	a = NULL;
	return (a);
}

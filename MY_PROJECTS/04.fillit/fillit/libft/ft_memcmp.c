/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fr_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:02:48 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/27 20:18:06 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	unsigned char *a;
	unsigned char *b;

	if (arr1 == arr2 || n == 0)
		return (0);
	a = (unsigned char *)arr1;
	b = (unsigned char *)arr2;
	while (n != 0)
	{
		if (*a != *b)
			return (*a - *b);
		if (n)
		{
			a++;
			b++;
		}
		n--;
	}
	return (0);
}

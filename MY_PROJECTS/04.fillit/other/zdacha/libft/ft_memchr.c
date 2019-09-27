/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:48:56 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/27 17:31:08 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *arr, int c, size_t n)
{
	char *a;
	char b;

	a = (char *)arr;
	b = (char)c;
	while (n != 0)
	{
		if (*a == b)
			return (a);
		else
			a++;
		n--;
	}
	return (NULL);
}

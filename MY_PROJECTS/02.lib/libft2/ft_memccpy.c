/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:34:36 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/15 20:13:54 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *out, const void *in, int c, size_t n)
{
	unsigned char	*a;
	char			*b;
	size_t			i;

	a = (unsigned char *)out;
	b = (char *)in;
	i = 0;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		a[i] = b[i];
		if (a[i] == (unsigned char)c)
			return (a + i + 1);
		i++;
	}
	return (NULL);
}

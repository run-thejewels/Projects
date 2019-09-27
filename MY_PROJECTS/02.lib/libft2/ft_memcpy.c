/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:31:51 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/03 14:50:56 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	dose_it_me(void *a, const void *b, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i <= n)
	{
		while (j <= n)
		{
			if (&a[i] == &b[j])
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

void		*ft_memcpy(void *out, const void *in, size_t n)
{
	unsigned char		*a;
	const unsigned char	*b;
	size_t				i;

	a = (unsigned char *)out;
	b = (unsigned char *)in;
	i = 0;
	if (n == 0 || dose_it_me(out, in, n) == 0)
		return (out);
	while (i < n)
	{
		a[i] = b[i];
		i++;
	}
	return (out);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:53:34 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/03 16:01:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *out, const void *in, size_t n)
{
	char	*a;
	char	*b;
	size_t	i;

	a = (char *)out;
	b = (char *)in;
	i = 0;
	if (a < b)
		while (i < n)
		{
			a[i] = b[i];
			i++;
		}
	else
	{
		a = a + n - 1;
		b = b + n - 1;
		while (n--)
		{
			*a = *b;
			a--;
			b--;
		}
	}
	return (out);
}

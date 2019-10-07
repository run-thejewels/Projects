/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 14:40:39 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/01 16:24:34 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*dst;
	int				i;
	int				buf;
	unsigned int	temp;

	buf = n;
	i = 1;
	while ((buf = buf / 10))
		i++;
	buf = 0;
	if (n < 0 && (buf = 1))
		temp = (unsigned int)(-n);
	else
		temp = (unsigned int)n;
	if (!(dst = (char *)malloc(i + buf + 1)))
		return (NULL);
	dst[i + buf] = '\0';
	while (--i > -1)
	{
		dst[i + buf] = (char)(temp % 10 + '0');
		temp = temp / 10;
	}
	if (buf)
		dst[0] = '-';
	return (dst);
}

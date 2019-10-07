/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:38:47 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/11 19:04:12 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long n)
{
	int			len;
	int			is_neg;
	long long	temp;
	char		*dst;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	temp = n;
	len = 1;
	while ((temp = temp / 10))
		len++;
	if (!(dst = (char *)malloc(sizeof(char) * (len + is_neg + 1))))
		return (NULL);
	if (is_neg)
		dst[0] = '-';
	dst[len + is_neg] = '\0';
	while (--len >= 0)
	{
		dst[len + is_neg] = (char)(ft_absll(n) % 10 + '0');
		n = n / 10;
	}
	return (dst);
}

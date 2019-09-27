/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:38:16 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/28 20:21:41 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	s[11];
	char	*res;
	int		neg;
	int		i;
	int		j;

	i = 0;
	j = 0;
	neg = n < 0 ? -1 : 1;
	while (neg * n > 9 || neg * n < 0)
	{
		s[i++] = '0' + neg * (n % 10);
		n = n / 10;
	}
	s[i++] = '0' + neg * n;
	if (neg < 0)
		s[i++] = '-';
	if ((res = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	res[i] = '\0';
	while (i--)
		res[i] = s[j++];
	return (res);
}

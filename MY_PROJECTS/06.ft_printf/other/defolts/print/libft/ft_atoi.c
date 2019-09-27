/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 15:58:27 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:36:53 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(const char *s)
{
	int				neg;
	int				i;
	long long int	n;
	long long int	k;

	i = 0;
	n = 0;
	neg = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\f'
			|| s[i] == '\t' || s[i] == '\r' || s[i] == '\v')
		i++;
	if (s[i] == 45)
		neg = 1;
	if (s[i] == 45 || s[i] == 43)
		i++;
	while (s[i] >= 48 && s[i] <= 57)
	{
		k = n;
		n *= 10;
		if (n < k)
			return (neg == 1 ? 0 : -1);
		n += ((int)s[i++] - 48);
	}
	return (neg == 1 ? -n : n);
}

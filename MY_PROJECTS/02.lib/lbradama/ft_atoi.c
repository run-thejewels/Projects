/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:59:04 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/09 20:05:37 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	end(unsigned long long int nbr, int n)
{
	if (nbr > 9223372036854775807 && n == 0)
		return (-1);
	else if (nbr > 9223372036854775808ull && n == 1)
		return (0);
	if (n == 1)
		return ((int)(-1 * nbr));
	else
		return ((int)(nbr));
}

int			ft_atoi(const char *str)
{
	unsigned long long int	nbr;
	int						n;
	int						i;

	nbr = 0;
	n = 0;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		n = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nbr *= 10;
		nbr += (int)str[i] - '0';
		i++;
	}
	if (nbr != 0)
		return (end(nbr, n));
	return (0);
}

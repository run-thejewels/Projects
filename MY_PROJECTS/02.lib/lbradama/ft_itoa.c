/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:29:21 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/14 14:27:20 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	from_darkside(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char		*ft_itoa(int n)
{
	int		i;
	int		l;
	int		nega;
	char	*a;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = n;
	l = 2;
	nega = 0;
	from_darkside(&n, &nega);
	while (i /= 10)
		l++;
	l += nega;
	if (!(a = (char*)malloc(sizeof(char) * l)))
		return (NULL);
	a[--l] = '\0';
	while (l--)
	{
		a[l] = n % 10 + '0';
		n = n / 10;
	}
	if (nega)
		a[0] = '-';
	return (a);
}

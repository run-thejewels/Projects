/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 21:41:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/03 20:00:44 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			numeric(int c)
{
	int		result;

	if (!c)
		return (1);
	result = 0;
	if (c < 0)
		result++;
	while (c)
	{
		c /= 10;
		result++;
	}
	return (result);
}

static int			shorter(int n)
{
	int				temp;
	int				temp_temp;
	int				correct;
	int				correct2;

	temp = ft_maxmin("int", "min");
	correct = numeric(n) - 2;
	correct2 = 1;
	if (n == temp)
	{
		while (correct--)
			correct2 *= 10;
		while (temp)
		{
			temp_temp = temp;
			temp /= 10;
		}
		temp = temp_temp * -1;
		ft_putchar((char)(temp + '0'));
		temp = n + (temp * correct2);
		return (temp * -1);
	}
	return (n * -1);
}

static int			multer(int mul)
{
	int				i;

	i = 1;
	while (mul - 1)
	{
		mul--;
		i *= 10;
	}
	return (i);
}

void				ft_putnbr(int n)
{
	int index;
	int temp;

	if (n < 0)
	{
		ft_putchar('-');
		n = shorter(n);
	}
	index = multer(numeric(n));
	while (index)
	{
		temp = n / index;
		ft_putchar(temp + '0');
		n = n - (temp * index);
		index /= 10;
	}
}

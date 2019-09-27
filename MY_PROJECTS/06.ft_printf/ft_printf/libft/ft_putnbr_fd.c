/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 22:01:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 22:01:42 by ahalmon-         ###   ########.fr       */
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

static int			check_maxmin(void)
{
	size_t			index;
	int				result;

	index = sizeof(int) * 8 - 1;
	result = 1;
	while (index)
	{
		result *= 2;
		index--;
	}
	return (result * -1);
}

static int			shorter(int n, int fd)
{
	int				temp;
	int				temp_temp;
	int				correct;
	int				correct2;

	temp = check_maxmin();
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
		ft_putchar_fd((char)(temp + '0'), fd);
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

void				ft_putnbr_fd(int n, int fd)
{
	int index;
	int temp;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = shorter(n, fd);
	}
	index = multer(numeric(n));
	while (index)
	{
		temp = n / index;
		ft_putchar_fd(temp + '0', fd);
		n = n - (temp * index);
		index /= 10;
	}
}

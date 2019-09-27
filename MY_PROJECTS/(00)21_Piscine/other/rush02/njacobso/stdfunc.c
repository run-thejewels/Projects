/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhoppe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:39:08 by jhoppe            #+#    #+#             */
/*   Updated: 2018/10/06 16:19:48 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_colle2.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_lenght(int chis)
{
	int	count;

	count = 0;
	while (chis != 0)
	{
		chis = chis / 10;
		count++;
	}
	return (count);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_negative(int nb)
{
	nb = -nb;
	ft_putchar(45);
	return (nb);
}

void	ft_putnbr(int nb)
{
	int		count;
	char	out[19];

	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		count = 0;
		if (nb < 0)
			nb = ft_negative(nb);
		count = ft_lenght(nb);
		out[count] = '\0';
		while (count > 0)
		{
			out[count - 1] = nb % 10 + 48;
			nb = nb / 10;
			count--;
		}
		while (out[count] != '\0')
		{
			ft_putchar(out[count]);
			count++;
		}
	}
}

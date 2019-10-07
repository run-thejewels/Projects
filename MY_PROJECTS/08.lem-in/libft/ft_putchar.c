/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:49:38 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/11/29 19:00:01 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	unsigned char	a;
	unsigned char	b;
	unsigned char	ch;

	if (!(c >> 7))
		write(1, &c, 1);
	else
	{
		ch = (unsigned char)c;
		a = 0b11000000 | (ch >> 6);
		b = (ch & 0b00111111) | 0b10000000;
		write(1, &a, 1);
		write(1, &b, 1);
	}
}

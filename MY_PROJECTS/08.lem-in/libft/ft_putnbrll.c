/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:31:33 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/11 19:14:16 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrll(long long n)
{
	long long temp;

	temp = -9223372036854775807;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == temp)
		{
			ft_putstr("9223372036854775807");
			return ;
		}
		else
			n = -n;
	}
	if (n > 9)
		ft_putnbrll(n / 10);
	ft_putchar((char)(n % 10 + '0'));
}

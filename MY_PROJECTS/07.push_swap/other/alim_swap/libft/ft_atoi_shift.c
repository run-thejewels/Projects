/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_shift.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 13:36:27 by rymuller          #+#    #+#             */
/*   Updated: 2019/05/03 19:19:20 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_atoi_shift(char **str)
{
	size_t		nbr;
	signed char	sign;

	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if ((**str == '+' && *(*str + 1) == '-')
			|| (**str == '-' && *(*str + 1) == '+'))
		return (0);
	if (**str == '+')
		(*str)++;
	if (**str == '-')
	{
		(*str)++;
		sign = -1;
	}
	nbr = 0;
	while (ft_isdigit(**str))
		nbr = nbr * 10 + *(*str)++ - '0';
	return (sign * nbr);
}

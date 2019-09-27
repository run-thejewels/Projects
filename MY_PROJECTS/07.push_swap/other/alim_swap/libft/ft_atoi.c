/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:05:14 by rymuller          #+#    #+#             */
/*   Updated: 2019/05/03 13:29:18 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	size_t		nbr;
	signed char	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if ((*str == '+' && *(str + 1) == '-')
			|| (*str == '-' && *(str + 1) == '+'))
		return (0);
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		sign = -1;
	}
	nbr = 0;
	while (ft_isdigit(*str))
	{
		if (nbr > ATOI_MAX || (nbr == ATOI_MAX && *str - '0' > 7))
			return ((sign == 1) ? -1 : 0);
		nbr = nbr * 10 + (*str++ - '0');
	}
	return (sign * nbr);
}

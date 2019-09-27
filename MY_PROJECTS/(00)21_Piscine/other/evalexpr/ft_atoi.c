/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:13:57 by kbethany          #+#    #+#             */
/*   Updated: 2018/10/07 18:11:47 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	ft_atoi(char *str)
{
	int nbr;
	int s;
	int i;

	nbr = 0;
	s = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;;
	}
	if (str[i] == '(')
	{
		i++;
		nbr = low_oper(str);
		if (str[i] == ')')
			i++;
		return (s * nbr);
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = (nbr * 10) + str[i] - '0';
		i++;
	}
	return (s * nbr);
}

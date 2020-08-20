/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_comparison.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:57:10 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:44:51 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_math_long_arithmetic_string_comparison_hhelper(char *n1, \
	char *n2)
{
	size_t	index;

	index = 0;
	while (n1[index])
	{
		if (n1[index] != n2[index])
		{
			if (n1[index] > n2[index])
				return (1);
			return (-1);
		}
		index++;
	}
	return (0);
}

static int	ft_math_long_arithmetic_string_ch(char *n1, char *n2)
{
	size_t	s1;
	size_t	s2;

	if (n1[0] == '-' && n2[0] != '-')
		return (-1);
	if (n2[0] == '-' && n1[0] != '-')
		return (1);
	if (n1[0] == '-' && n2[0] == '-')
		return (ft_math_long_arithmetic_string_ch(&n2[1], &n1[1]));
	s1 = ft_strlen(n1);
	s2 = ft_strlen(n2);
	if (s1 > s2)
		return (1);
	else if (s2 > s1)
		return (-1);
	return (ft_math_long_arithmetic_string_comparison_hhelper(n1, n2));
}

int			ft_math_longar_str_comparison(char *n1, char *n2)
{
	if (!n1 || !n2)
		return (3);
	if (!ft_strcmp(n1, n2))
		return (0);
	return (ft_math_long_arithmetic_string_ch(n1, n2));
}

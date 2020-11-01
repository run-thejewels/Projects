/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <kbethany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:12:14 by kbethany          #+#    #+#             */
/*   Updated: 2020/11/01 17:12:56 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	max_f(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	mod_f(float a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

void	isometric(float *x, float *y, int z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

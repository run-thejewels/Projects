/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_module_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 18:40:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 18:52:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_math_module_int(int num)
{
	int		temp;

	if (num == 0 || num == -0)
		return (0);
	if (num > 0)
		return (num);
	temp = num * -1;
	if (temp * -1 == num)
		return (temp);
	return (0);
}

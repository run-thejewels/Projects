/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_byte.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:14:17 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/20 18:26:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_swap_byte(void *x, void *y)
{
	unsigned char	temp;
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)x;
	b = (unsigned char *)y;
	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}

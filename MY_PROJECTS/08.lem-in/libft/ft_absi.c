/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_absi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:25:11 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/24 13:09:03 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_absi(int n)
{
	unsigned int	dst;

	if (n < 0)
		dst = (unsigned int)(-n);
	else
		dst = (unsigned int)n;
	return (dst);
}

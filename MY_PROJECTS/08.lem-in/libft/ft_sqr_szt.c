/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr_szt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 15:59:21 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/07 16:08:10 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_sqr_szt(size_t nbr, size_t rank)
{
	size_t		dst;

	if (rank == 0)
		return (1);
	dst = 1;
	while (rank > 0)
	{
		dst *= nbr;
		rank--;
	}
	return (dst);
}

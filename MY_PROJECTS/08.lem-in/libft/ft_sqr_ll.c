/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqr_ll.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:15:09 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/07/20 19:33:31 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_sqr_ll(long long nbr, size_t rank)
{
	long long	dst;

	dst = 1;
	if (rank == 0)
		return (1);
	while (rank > 0)
	{
		dst *= nbr;
		rank--;
	}
	return (dst);
}

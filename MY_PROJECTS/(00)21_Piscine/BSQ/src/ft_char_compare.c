/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_compare.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:19:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 19:18:31 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_char_compare(char victim, char c1, char c2, char c3)
{
	if (victim == c1 || victim == c2 || victim == c3)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:46:29 by kbethany          #+#    #+#             */
/*   Updated: 2019/03/01 18:33:02 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

size_t	digit(int n, int t)
{
	char	*a;

	if (n == 1 || n == 3)
		a = ft_itoa(t);
	else if (n == 2)
		a = ft_itoa_base(t, 8);
	else
		a = ft_itoa_base(t, 16);
	return(myputstr(a));
}

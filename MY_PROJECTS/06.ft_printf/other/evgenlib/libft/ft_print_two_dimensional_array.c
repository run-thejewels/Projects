/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_two_dimensional_array.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 23:54:19 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/06 00:04:38 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_print_two_dimensional_array(char **str)
{
	size_t	index;

	if (!str)
		return ;
	index = 0;
	while (str[index])
	{
		ft_putendl(str[index]);
		index++;
	}
}

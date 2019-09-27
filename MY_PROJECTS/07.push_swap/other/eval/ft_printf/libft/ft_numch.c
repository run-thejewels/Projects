/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 00:16:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/06 00:21:52 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_numch(char *str, char ch)
{
	size_t	num;
	size_t	index;

	if (!str)
		return (0);
	num = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == ch)
			num++;
		index++;
	}
	return (num);
}

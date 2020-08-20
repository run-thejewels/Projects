/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letter_replacement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 00:05:28 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/06 00:12:30 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_letter_replacement(char *str, char previous, char new)
{
	size_t		index;

	index = 0;
	while (str[index])
	{
		if (str[index] == previous)
			str[index] = new;
		index++;
	}
	return (str);
}

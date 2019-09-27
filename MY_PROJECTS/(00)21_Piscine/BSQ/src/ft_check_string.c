/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 21:19:34 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 19:24:44 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_check_string(char *str, t_mapdata *mapdata)
{
	int i;

	i = 0;
	if (ft_strlen(0, str, '\0') != mapdata->x)
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_char_compare(str[i], mapdata->empty, mapdata->obstacle, '\n'))
			return (0);
		i++;
	}
	return (1);
}

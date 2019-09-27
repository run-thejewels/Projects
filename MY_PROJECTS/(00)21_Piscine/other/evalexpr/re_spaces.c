/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_spaces.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:37:23 by kbethany          #+#    #+#             */
/*   Updated: 2018/10/07 17:13:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes.h"

char	*re_spaces(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			res[j] = str[i];
			j = j + 1;
		}
		i = i + 1;
	}
	res[j] = '\0';
	return (res);
}

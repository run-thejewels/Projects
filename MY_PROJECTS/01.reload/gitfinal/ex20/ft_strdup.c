/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:55:44 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/28 13:40:27 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*cp;
	int		j;
	int		i;

	j = 0;
	while (src[j] != '\0')
		j++;
	cp = (char*)malloc(sizeof(char*) * j);
	i = 0;
	while (i < j)
	{
		cp[i] = src[i];
		i++;
	}
	cp[j] = '\0';
	return (cp);
}

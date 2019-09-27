/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:23:20 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/11/29 16:45:09 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncat(char *dst, const char *app, size_t n)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i])
		i++;
	while (app[k] && k < n)
		dst[i++] = app[k++];
	dst[i] = '\0';
	return (dst);
}

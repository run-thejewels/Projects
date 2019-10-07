/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:16:28 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/15 20:19:34 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;
	size_t	i;

	if (size + 1 < size)
		return (NULL);
	i = 0;
	if (!(dst = (char *)malloc(size + 1)))
		return (NULL);
	while (i <= size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 22:31:11 by forange-          #+#    #+#             */
/*   Updated: 2019/08/17 23:48:44 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewc(size_t size, char c)
{
	char	*dst;
	size_t	i;

	if (size + 1 < size)
		return (NULL);
	i = 0;
	if (!(dst = (char *)malloc(size + 1)))
		return (NULL);
	while (i < size)
	{
		dst[i] = c;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

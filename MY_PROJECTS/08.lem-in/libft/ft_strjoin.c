/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 20:17:35 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/11/30 16:20:17 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	char			*dst;

	if (!s1 || !s2)
		return (NULL);
	i = (unsigned int)ft_strlen(s1) + (unsigned int)ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strcpy(dst, s1);
	ft_strcpy(&dst[ft_strlen(s1)], s2);
	dst[i] = '\0';
	return (dst);
}

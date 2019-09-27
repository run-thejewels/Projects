/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 19:03:23 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/22 19:19:25 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;

	if (!(dst = (char *)malloc(sizeof(*s1) * \
					(ft_strlen(s1) + 1))))
		return (NULL);
	ft_strcpy(dst, s1);
	return (dst);
}

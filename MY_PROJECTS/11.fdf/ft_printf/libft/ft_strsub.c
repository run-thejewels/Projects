/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 00:49:31 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 17:51:12 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;

	if (!s)
		return (NULL);
	if (!(ft_strlen(s) - start >= len))
		return (NULL);
	if (len + 1 <= len || !(result = (char *)malloc(len + 1)))
		return (NULL);
	ft_strncpy(result, s + start, len);
	result[len] = '\0';
	return (result);
}

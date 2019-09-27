/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:09:07 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:40:57 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*a;
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	if (!*s || start > (unsigned int)ft_strlen(s))
		return (NULL);
	if ((a = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len && s[start] != '\0')
	{
		a[i++] = s[start++];
	}
	a[i] = '\0';
	return (a);
}

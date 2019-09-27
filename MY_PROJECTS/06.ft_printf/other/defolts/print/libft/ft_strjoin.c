/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 13:58:38 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:39:33 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*s;
	int					i;
	unsigned int		k;
	int					l;

	k = 0;
	l = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if ((s = (char *)malloc(sizeof(s) * (i + 1))) == NULL)
		return (NULL);
	while (s1[l])
		s[k++] = s1[l++];
	l = 0;
	while (s2[l] != '\0')
		s[k++] = s2[l++];
	s[k] = '\0';
	return (s);
}

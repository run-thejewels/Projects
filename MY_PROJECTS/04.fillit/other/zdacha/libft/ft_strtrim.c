/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 14:19:15 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:41:10 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
	char	*a;

	if (!s)
		return (NULL);
	i = -1;
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\t' || s[l - 1] == '\n')
		l--;
	while (s[++i] == ' ' || s[i] == '\t' || s[i] == '\n')
		l--;
	if (l < 0)
		l = 0;
	a = (char *)malloc(l + 1);
	if (a == NULL)
		return (NULL);
	s += i;
	i = 0;
	while (i < l)
		a[i++] = *s++;
	a[i] = '\0';
	return (a);
}

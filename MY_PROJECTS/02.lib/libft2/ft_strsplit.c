/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:24:26 by kbethany          #+#    #+#             */
/*   Updated: 2019/01/07 16:27:03 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wcount(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		w;

	i = 0;
	j = 0;
	w = 0;
	while (s[i])
	{
		if (s[i] == c && w == 1)
			w = 0;
		if (s[i] != c && w == 0)
		{
			w = 1;
			j++;
		}
		i++;
	}
	return (j);
}

static size_t	len(char const *s, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] && s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**a;

	i = 0;
	if (!s)
		return (NULL);
	j = wcount(s, c);
	if (!(a = (char**)malloc(sizeof(char *) * (j + 1))))
		return (NULL);
	while (j--)
	{
		while (*s == c && *s != '\0')
			s++;
		a[i] = ft_strsub(s, 0, len(s, c));
		if (a[i] == NULL)
		{
			kish(a);
			return (NULL);
		}
		s = s + len(s, c);
		i++;
	}
	a[i] = NULL;
	return (a);
}

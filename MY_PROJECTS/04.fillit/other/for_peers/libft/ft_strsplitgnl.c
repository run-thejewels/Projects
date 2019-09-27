/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:26:01 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:43:02 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static int		ft_colwr(const char *s, char c)
{
	int		k;
	int		flag;

	flag = 0;
	k = 0;
	while (*s != '\0')
	{
		if (flag == 1 && *s == c)
			flag = 0;
		if (flag == 0 && *s != c)
		{
			flag = 1;
			k++;
		}
		s++;
	}
	return (k);
}

static int		ft_wlen(const char *s, char c)
{
	int		l;

	l = 0;
	while (*s != c && *s != '\0')
	{
		l++;
		s++;
	}
	return (l);
}

static void		ft_del(char ***a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(*a[i]);
		i++;
	}
	free(*a);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		nw;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	nw = ft_colwr(s, c);
	a = (char **)malloc(sizeof(*a) * (ft_colwr(s, c) + 1));
	if (a == NULL)
		return (NULL);
	while (nw--)
	{
		while (*s == c && *s != '\0')
			s++;
		if ((a[i] = ft_strsub(s, 0, ft_wlen(s, c))) == NULL)
		{
			ft_del(&a, i);
			return (NULL);
		}
		s = s + ft_wlen(s, c);
		i++;
	}
	a[i] = NULL;
	return (a);
}

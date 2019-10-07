/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:27:02 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/15 20:20:04 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strsplit_count(char const *s, char c)
{
	size_t	dst;
	size_t	i;

	dst = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			dst++;
		while (s[i] != c && s[i])
			i++;
	}
	return (dst);
}

static char		*ft_strsplit_newword(char const *s, char c, size_t *begin)
{
	char	*dst;
	size_t	end;

	while (s[*begin] && s[*begin] == c)
		(*begin)++;
	end = *begin;
	while (s[end] && s[end] != c)
		end++;
	dst = ft_strsub(s, *begin, end - *begin);
	*begin = end;
	return (dst);
}

static void		ft_strsplit_abortfunc(char **s, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		ft_strdel(&s[i]);
		i++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	words;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	words = ft_strsplit_count(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (j < words)
	{
		if (!(dst[j] = ft_strsplit_newword(s, c, &i)))
		{
			ft_strsplit_abortfunc(dst, words);
			free(dst);
			dst = NULL;
			return (NULL);
		}
		j++;
	}
	dst[words] = NULL;
	return (dst);
}

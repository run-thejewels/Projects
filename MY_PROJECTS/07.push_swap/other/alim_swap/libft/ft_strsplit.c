/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:39:38 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/30 21:36:20 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_num(const char *s, char c)
{
	size_t		i;
	size_t		words_num;

	i = 0;
	words_num = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (s[i + 1] == c || s[i + 1] == '\0')
				words_num++;
		i++;
	}
	return (words_num);
}

static size_t	word_len(const char *s, char c)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		return (i);
	}
	return (0);
}

static char		**ft_words(char const *s, char **words, char c, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < len)
	{
		while (s[k] == c)
			k++;
		if (!(words[i] =
					(char *)malloc(sizeof(char) * (word_len(&s[k], c) + 1))))
		{
			while (i != 0)
				free(words[--i]);
			free(words);
			return (NULL);
		}
		while (s[k] != c && s[k] != '\0')
			words[i][j++] = s[k++];
		words[i++][j] = '\0';
		j = 0;
	}
	return (words);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		len;
	char		**words;

	if (s != NULL)
	{
		len = words_num(s, c);
		if (!(words = (char **)malloc(sizeof(char *) * (len + 1))))
			return (NULL);
		words[len] = NULL;
		return (ft_words(s, words, c, len));
	}
	return (NULL);
}

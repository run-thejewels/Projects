/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 02:35:27 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/04 21:05:04 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*space_to_letters(const char *str, char c)
{
	size_t		index;
	char		*result;

	index = 0;
	while (str[index] != c)
	{
		if (!(str[index]))
			break ;
		index++;
	}
	if (index + 1 <= index || !(result = (char *)malloc(index + 1)))
		return (NULL);
	result[index] = '\0';
	index = 0;
	while (str[index] != c)
	{
		if (!(str[index]))
			break ;
		result[index] = str[index];
		index++;
	}
	return (result);
}

static size_t	number_words(const char *str, char c)
{
	size_t		index;
	int			word_indicate;
	size_t		result;

	index = 0;
	word_indicate = 0;
	result = 0;
	while (str[index])
	{
		if (str[index] != c)
			word_indicate = 1;
		if (str[index] == c && word_indicate != 0)
		{
			result++;
			word_indicate = 0;
		}
		index++;
	}
	if (word_indicate)
		result++;
	return (result);
}

static int		make_job(char **result, const char *s, char c)
{
	size_t		index;
	int			word_indicate;
	size_t		word_num;

	index = 0;
	word_indicate = 0;
	word_num = 0;
	while (s[index])
	{
		if (s[index] != c && !word_indicate)
		{
			if (!(result[word_num] = space_to_letters(s + index, c)))
				return (0);
			word_indicate = 1;
			word_num++;
		}
		if (s[index] == c)
			word_indicate = 0;
		index++;
	}
	return (1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**result;

	if (!s)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (number_words(s, c) + 1))))
		return (NULL);
	result[number_words(s, c)] = NULL;
	if (!(make_job(result, s, c)))
	{
		ft_free_two_dimensional_array((void **)result);
		return (NULL);
	}
	return (result);
}

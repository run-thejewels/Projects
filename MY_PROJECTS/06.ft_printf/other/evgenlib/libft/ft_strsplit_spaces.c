/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spaces.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:29:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/21 19:41:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*space_to_letters(const char *str)
{
	size_t		index;
	char		*result;

	index = 0;
	while (!ft_isspace(str[index]))
	{
		if (!(str[index]))
			break ;
		index++;
	}
	if (index + 1 <= index || !(result = (char *)malloc(index + 1)))
		return (NULL);
	result[index] = '\0';
	index = 0;
	while (!ft_isspace(str[index]))
	{
		if (!(str[index]))
			break ;
		result[index] = str[index];
		index++;
	}
	return (result);
}

static size_t	number_words(const char *str)
{
	size_t		index;
	int			word_indicate;
	size_t		result;
	int			temp;

	index = 0;
	word_indicate = 0;
	result = 0;
	while (str[index])
	{
		if (!(temp = ft_isspace(str[index])))
			word_indicate = 1;
		if (temp && word_indicate != 0)
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

static int		make_job(char **result, const char *s)
{
	size_t		index;
	int			word_indicate;
	size_t		word_num;
	int			temp;

	index = 0;
	word_indicate = 0;
	word_num = 0;
	while (s[index])
	{
		if (!(temp = ft_isspace(s[index])) && !word_indicate)
		{
			if (!(result[word_num] = space_to_letters(s + index)))
				return (0);
			word_indicate = 1;
			word_num++;
		}
		if (temp)
			word_indicate = 0;
		index++;
	}
	return (1);
}

char			**ft_strsplit_spaces(char const *s)
{
	char		**result;

	if (!s)
		return (NULL);
	if (!(result = (char **)malloc(sizeof(char *) * (number_words(s) + 1))))
		return (NULL);
	result[number_words(s)] = NULL;
	if (!(make_job(result, s)))
	{
		ft_free_two_dimensional_array((void **)result);
		return (NULL);
	}
	return (result);
}

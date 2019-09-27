/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 01:58:14 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/02 20:04:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		yes(char *s)
{
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		else
			return (0);
	}
	return (1);
}

static size_t	clear_len(char *s)
{
	size_t		index;

	index = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (!yes(s) && *s)
	{
		index++;
		s++;
	}
	return (index);
}

static void		make_job(char *s, char *result)
{
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (!yes(s) && *s)
	{
		*result = *s;
		result++;
		s++;
	}
}

char			*ft_strtrim(char const *s)
{
	char		*result;
	size_t		size;

	if (!s)
		return (NULL);
	size = clear_len((char *)s);
	if (size + 1 <= size || !(result = (char *)malloc(size + 1)))
		return (NULL);
	result[size] = '\0';
	make_job((char *)s, result);
	return (result);
}

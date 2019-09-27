/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:07:56 by rymuller          #+#    #+#             */
/*   Updated: 2018/11/29 20:29:46 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*mal;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s != NULL)
	{
		start = 0;
		while (iswhitespace(s[start]))
			start++;
		end = ft_strlen(s) - 1;
		if (start == end + 1)
			return (ft_strnew(0));
		while (iswhitespace(s[end]))
			end--;
		if (!(mal = (char *)malloc(end - start + 2)))
			return (NULL);
		i = 0;
		while (start <= end)
			mal[i++] = s[start++];
		mal[i] = '\0';
		return (mal);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:35:06 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/17 16:59:41 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	char	*f;

	i = 0;
	if (ft_strlen(s2) == 0 || ft_strcmp(s1, s2) == 0)
		return ((char *)s1);
	else if (n == 0 || ft_strlen(s1) == 0)
		return (NULL);
	while (s1[i] && i < n)
	{
		if (s1[i] == s2[0] && i + ft_strlen(s2) < n + 1)
		{
			f = (char *)s1 + i;
			if (ft_strncmp(f, (char *)s2, ft_strlen(s2)) == 0)
				return (f);
		}
		i++;
	}
	return (NULL);
}

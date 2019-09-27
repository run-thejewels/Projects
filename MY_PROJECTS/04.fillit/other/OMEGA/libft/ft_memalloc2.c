/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:17:39 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/01/28 19:45:42 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_del(char ***a, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(*a[i]);
		*a[i] = NULL;
		i++;
	}
	free(*a);
	*a = NULL;
	return (NULL);
}

char	**ft_memalloc2(size_t i, size_t j)
{
	char	**s;
	size_t	k;
	size_t	l;

	k = -1;
	if ((s = (char **)malloc(sizeof(char *) * (i + 1))) == NULL)
		return (NULL);
	while (++k < i)
		if ((s[k] = (char *)malloc(sizeof(char) * j)) == NULL)
			return (ft_del(&s, k));
	k = 0;
	while (k < i)
	{
		l = 0;
		while (l < j)
		{
			s[k][l] = '.';
			l++;
		}
		s[k][l] = '\0';
		k++;
	}
	s[i] = NULL;
	return (s);
}

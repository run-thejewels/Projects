/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:10:44 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/15 20:04:26 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	useless(char const *s, int *i, int *j)
{
	while (s[*i] == ' ' || s[*i] == '\n' || s[*i] == '\t')
		(*i)++;
	while (s[*j] == ' ' || s[*j] == '\n' || s[*j] == '\t')
		(*j)--;
}

char		*ft_strtrim(char const *s)
{
	char	*a;
	int		i;
	int		j;
	int		z;

	i = 0;
	z = 0;
	a = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s) - 1;
	useless(s, &i, &j);
	if (i == (int)ft_strlen(s))
		return (ft_strnew(0));
	if (!(a = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	while (z < j - i + 1)
	{
		a[z] = s[i + z];
		z++;
	}
	a[z] = '\0';
	return (a);
}

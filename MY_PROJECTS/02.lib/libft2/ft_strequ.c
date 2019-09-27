/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 20:23:09 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/10 20:33:30 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	if (s1 == NULL || s2 == NULL)
		return (0);
	if (ft_strlen(s1) == ft_strlen(s2))
		while (s1[i] && s2[i])
		{
			if (s1[i] != s2[i])
				c = 0;
			i++;
		}
	else
		c = 0;
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:55:53 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/04 15:55:39 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *s_out, const char *s_in, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s_in[i] == '\0')
		{
			while (i < n)
			{
				s_out[i] = '\0';
				i++;
			}
			return (s_out);
		}
		s_out[i] = s_in[i];
		i++;
	}
	return (s_out);
}

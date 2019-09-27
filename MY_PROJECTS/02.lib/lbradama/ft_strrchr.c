/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:57:23 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/06 20:00:19 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*f;
	char	*h;

	h = NULL;
	f = (char *)s;
	while (*f != '\0')
	{
		if (*f == (char)c)
			h = f;
		f++;
	}
	if (c == '\0')
		return (f);
	return (h);
}

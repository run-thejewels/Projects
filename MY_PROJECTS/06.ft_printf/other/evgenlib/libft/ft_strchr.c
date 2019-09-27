/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 03:51:30 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/08 20:49:56 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *string, int symbol)
{
	size_t	where;
	char	*temp;

	where = 0;
	temp = (char *)string;
	while (1)
	{
		if (temp[where] == (char)symbol)
			return (temp + where);
		if (temp[where] == '\0')
			break ;
		where++;
	}
	return (NULL);
}

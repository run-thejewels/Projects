/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 04:05:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/08 20:50:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *string, int symbol)
{
	size_t	where;
	char	*result;
	char	*temp;

	where = 0;
	result = NULL;
	temp = (char *)string;
	while (1)
	{
		if (temp[where] == (char)symbol)
			result = (temp + where);
		if (temp[where] == '\0')
			break ;
		where++;
	}
	return (result);
}

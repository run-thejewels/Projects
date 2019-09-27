/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_disnuller_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 23:00:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/29 23:11:42 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_disnuller_end(char *str)
{
	size_t	null_indicate;
	size_t	index;

	if (!str)
		return (NULL);
	null_indicate = 0;
	index = 0;
	while (str[index])
	{
		if (str[index] == '0')
			null_indicate++;
		else
			null_indicate = 0;
		index++;
	}
	if (null_indicate)
		str[ft_strlen_safe(str) - null_indicate] = '\0';
	return (str);
}

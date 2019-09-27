/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:16:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/06 22:20:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_lower(char *str)
{
	char	*temp;

	temp = str;
	if (!str)
		return (NULL);
	while (*str)
	{
		*str = ft_tolower(*str);
		str++;
	}
	return (temp);
}

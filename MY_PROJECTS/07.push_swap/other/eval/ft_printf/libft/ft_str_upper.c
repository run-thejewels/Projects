/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_upper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 22:20:38 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/06 22:21:26 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_upper(char *str)
{
	char	*temp;

	temp = str;
	if (!str)
		return (NULL);
	while (*str)
	{
		*str = ft_toupper(*str);
		str++;
	}
	return (temp);
}

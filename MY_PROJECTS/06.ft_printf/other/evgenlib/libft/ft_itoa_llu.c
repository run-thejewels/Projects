/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 18:49:26 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/14 19:02:44 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_llu_size(unsigned long long int num)
{
	size_t		size;

	if (!num)
		return (1);
	size = 0;
	while (num)
	{
		num /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa_llu(unsigned long long int num)
{
	char		*result;
	size_t		size;

	size = ft_itoa_llu_size(num);
	if (!num)
		return (ft_strnew_filler(1, '0'));
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	result[size] = '\0';
	while (num)
	{
		result[size - 1] = num % 10 + '0';
		size--;
		num /= 10;
	}
	return (result);
}

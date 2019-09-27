/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_exponent_mix.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:10:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:45:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_math_longar_str_exponent_mix(char *num, \
	unsigned long int exponent)
{
	char	*result;
	char	*temp;

	if (!num)
		return (NULL);
	if (!exponent && num[0] == '0')
		return (ft_strnew_filler(1, '0'));
	if (!exponent)
		return (ft_strnew_filler(1, '1'));
	if (exponent == 1)
		return (ft_strdup(num));
	if (!(result = ft_strdup(num)))
		return (NULL);
	if (!(temp = ft_strdup(num)))
		return (NULL);
	while (exponent > 1)
	{
		result = ft_math_longar_str_multi_free_1(result, temp);
		exponent--;
	}
	free(temp);
	return (result);
}

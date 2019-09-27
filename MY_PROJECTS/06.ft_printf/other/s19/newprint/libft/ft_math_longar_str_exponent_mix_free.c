/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_exponent_mix_free.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 20:07:50 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/29 20:08:08 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_math_longar_str_exponent_mix_free(char *num, \
	unsigned long int exponent)
{
	char	*result;

	if (!(result = ft_math_longar_str_exponent_mix(num, exponent)))
		return (NULL);
	free(num);
	return (result);
}

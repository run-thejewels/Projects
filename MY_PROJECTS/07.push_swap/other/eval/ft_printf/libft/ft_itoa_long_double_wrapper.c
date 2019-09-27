/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double_wrapper.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 14:44:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 15:38:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_long_double_wrapper(long double num, size_t accuracy)
{
	char	*result;
	char	*dot;
	size_t	size;

	if (num != -0.0 && num != 0.0)
		result = ft_itoa_long_double_old(num, accuracy);
	else
		return (ft_strjoin_free_2("0.", ft_new_null_str(accuracy)));
	if ((dot = ft_strchr(result, '.')))
	{
		if ((size = ft_strlen(dot)) < accuracy + 1)
			result = ft_strjoin_fr_both(result, \
				ft_new_null_str(size - 1 - accuracy));
	}
	else
	{
		result = ft_strjoin_free_1(result, ".");
		result = ft_strjoin_fr_both(result, ft_new_null_str(accuracy));
	}
	return (result);
}

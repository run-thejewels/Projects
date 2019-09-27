/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_multi_free_both.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:22:48 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:23:01 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_math_longar_str_multi_free_both(char *n1, char *n2)
{
	char	*result;

	if (!(result = ft_math_longar_str_multi(n1, n2)))
		return (NULL);
	ft_free_both(n1, n2);
	return (result);
}

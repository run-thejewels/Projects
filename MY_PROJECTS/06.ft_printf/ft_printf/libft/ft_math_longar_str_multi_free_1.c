/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_multi_free_1.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:18:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:18:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_math_longar_str_multi_free_1(char *n1, char *n2)
{
	char	*result;

	if (!(result = ft_math_longar_str_multi(n1, n2)))
		return (NULL);
	free(n1);
	return (result);
}

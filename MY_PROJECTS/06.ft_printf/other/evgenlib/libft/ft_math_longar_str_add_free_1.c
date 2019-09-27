/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_add_free_1.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 22:03:46 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/23 22:03:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_math_longar_str_add_free_1(char *n1, char *n2)
{
	char *result;

	if (!(result = ft_math_longar_str_add(n1, n2)))
		return (NULL);
	free(n1);
	return (result);
}

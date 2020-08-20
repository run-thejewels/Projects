/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_not_bzero.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 22:05:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/04 22:10:00 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew_not_bzero(size_t size)
{
	char	*result;

	if (size + 1 <= size)
		return (NULL);
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	return (result);
}

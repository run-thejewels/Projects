/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_width_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:27:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/27 23:30:26 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_str_width_free(char *str, \
	char filler, size_t len, char *flags)
{
	char	*result;

	result = ft_str_width(str, filler, len, flags);
	free(str);
	return (result);
}

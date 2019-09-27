/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:18:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/04 17:18:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_jump(void *pointer, size_t n)
{
	if (!pointer)
		return (NULL);
	if (pointer + n > pointer)
		return (pointer + n);
	return (NULL);
}

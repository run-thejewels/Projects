/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jump_pointer_to_n.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 18:16:34 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/06 19:46:20 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_jump_pointer_to_n(void *pointer, int n)
{
	char	*temp_pointer;
	size_t	n_temp;

	if (!pointer)
		return (NULL);
	temp_pointer = (char *)pointer;
	if (n >= 0)
		n_temp = (size_t)n;
	else
	{
		n_temp = (size_t)(n * -1);
		return (temp_pointer - n_temp);
	}
	return (temp_pointer + n_temp);
}

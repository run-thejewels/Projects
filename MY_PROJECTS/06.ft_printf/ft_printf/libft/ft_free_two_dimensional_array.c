/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_two_dimensional_array.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:43:44 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/27 23:46:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_two_dimensional_array(void **arr)
{
	void	**temp;

	if (!arr)
		return ;
	temp = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(temp);
}

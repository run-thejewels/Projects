/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   how_many_steps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:36:47 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/22 21:36:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

size_t how_many_steps_to_get_out(size_t index, size_t size)
{
	size_t up;
	size_t down;

	up = index;
	down = size - index;
	if (up < down)
		return (up);
	return (down);
}

int do_up(size_t index, size_t size)
{
	size_t up;
	size_t down;

	up = index;
	down = size - index;
	if (up < down)
		return (1);
	return (0);
}

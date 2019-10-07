/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:47:49 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/19 03:56:59 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room		**new_room_array(int size)
{
	t_room	**dst;

	if (size < 1 || size >= size + 1)
		return (NULL);
	if (!(dst = (t_room **)malloc(sizeof(t_room *) * (size + 1))))
		return (NULL);
	while (size >= 0)
		dst[size--] = NULL;
	return (dst);
}

t_room		**make_bigger_array_and_fill(t_room **arr, t_room *link)
{
	t_room		**new_arr;
	int			i;
	int			size;

	if (!link)
		return (NULL);
	if (!arr)
	{
		new_arr = new_room_array(1);
		new_arr[0] = link;
		return (new_arr);
	}
	size = 0;
	while (arr[size])
		size++;
	if (!(new_arr = new_room_array(size + 1)))
		return (NULL);
	i = -1;
	while (++i < size)
		new_arr[i] = arr[i];
	new_arr[i] = link;
	free(arr);
	return (new_arr);
}

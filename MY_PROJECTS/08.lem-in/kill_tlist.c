/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_tlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:28:21 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/01 17:31:47 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		kill_tlist(t_list *lst, short free_content)
{
	t_list		*tmp;
	t_room		*room;

	if (!lst)
		return ;
	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (free_content && (room = tmp->content))
		{
			if (room->name)
				free(room->name);
			free(room);
		}
		free(tmp);
	}
}

void		kill_tlist_array(t_list **arr, short free_content)
{
	short		i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		kill_tlist(arr[i], free_content);
		i++;
	}
	free(arr);
}

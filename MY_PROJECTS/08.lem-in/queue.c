/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:57:35 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/09/23 12:17:36 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		queue_push_back(t_list *queue, void *void_ptr, t_data *s)
{
	t_list	*tmp;

	if (!queue || !void_ptr || !s)
		return ;
	if (!(tmp = ft_lstnew_fag(void_ptr, 0)))
		return ;
	while (queue->next)
		queue = queue->next;
	queue->next = tmp;
}

t_list		*queue_kill_go_next(t_list *queue, t_room *room, t_data *s)
{
	t_list	*tmp;

	if (!queue || !room || !s)
	{
		ft_lstdel_fag(&queue);
		free_exit(room, s, 0, "queue_kill_go_next empty ptr");
	}
	tmp = queue;
	queue = queue->next;
	free(tmp);
	return (queue);
}

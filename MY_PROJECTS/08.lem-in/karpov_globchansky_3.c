/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karpov_globchansky_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:47:16 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/01 15:54:26 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		change_way_number(t_list *way, int way1, int way2)
{
	if (!way)
		return ;
	while (way)
	{
		if (((t_room *)(way->content))->way == way1)
			((t_room *)(way->content))->way = way2;
		else if (((t_room *)(way->content))->way == way2)
			((t_room *)(way->content))->way = way1;
		way = way->next;
	}
}

void			its_alive(t_list **way_arr, t_data *s)
{
	t_list	*head;

	if (!way_arr || !s)
		return ;
	head = way_arr[s->conflict_way1 - 1];
	while (head->next)
		head = head->next;
	head->next = s->tail2;
	change_way_number(head, s->conflict_way1, s->conflict_way2);
	head = way_arr[s->conflict_way2 - 1];
	while (head->next)
		head = head->next;
	head->next = s->tail1;
	change_way_number(head->next, s->conflict_way1, s->conflict_way2);
}

static size_t	renumber_way_len(t_list *lst)
{
	if (!lst)
		return (0);
	if (!(lst->next))
	{
		lst->content_size = 0;
		return (0);
	}
	lst->content_size = renumber_way_len(lst->next) + 1;
	return (lst->content_size);
}

void			renumber_way_array_len(t_list **way_arr, t_data *s)
{
	short	i;

	if (!way_arr || !s)
		return ;
	i = 0;
	while (way_arr[i])
	{
		renumber_way_len(way_arr[i]);
		i++;
	}
}

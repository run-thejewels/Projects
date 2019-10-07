/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   karpov-globchansky_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:08:19 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/01 15:52:28 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		find_ways(t_list **way_arr, t_data *s)
{
	int		i;
	t_list	*way;

	if (!way_arr || !s)
		return (-1);
	i = 0;
	while (way_arr[i + 1])
		i++;
	while (i >= 0)
	{
		way = way_arr[i];
		while (way && (((t_room *)(way->content))->way == 0 || \
					((t_room *)(way->content))->way == i + 1))
			way = way->next;
		if (!way)
			i--;
		else
			break ;
	}
	if (i < 0)
		return (-1);
	s->conflict_way1 = i + 1;
	s->conflict_way2 = ((t_room *)(way->content))->way;
	return (0);
}

static void		cut_middle(t_list *head, t_list *tail, t_data *s)
{
	t_list	*middle;

	if (!head || !(head->next) || !tail)
		return ;
	middle = head;
	while (middle->next && middle->next != tail)
		middle = middle->next;
	middle->next = NULL;
	s->end_conf = ((t_room *)(head->content))->name;
	s->start_conf = ((t_room *)(middle->content))->name;
	kill_tlist(head->next, 0);
	head->next = NULL;
}

static t_list	*cut_way1(t_list **way_arr, int way1, int way2, t_data *s)
{
	t_list	*tail;
	t_list	*head;

	if (!way_arr || !s)
		return (NULL);
	head = way_arr[way2 - 1];
	while (head && ((t_room *)(head->content))->way != way1)
		head = head->next;
	tail = head;
	while (tail && tail->next && ((t_room *)(tail->content))->way == way1)
		tail = tail->next;
	if (!tail)
		return (NULL);
	cut_middle(head, tail, s);
	return (tail);
}

static t_list	*cut_way2(t_list **way_arr, int way_num, t_data *s)
{
	t_list	*way;
	t_list	*tmp;

	if (!way_arr || !s)
		return (NULL);
	way = way_arr[way_num - 1];
	while (way && ((t_room *)(way->content))->name != s->start_conf)
		way = way->next;
	if (!way)
		return (NULL);
	tmp = way;
	way = way->next;
	tmp->next = NULL;
	while (way && ((t_room *)(way->content))->name != s->end_conf)
	{
		tmp = way;
		way = way->next;
		free(tmp);
	}
	tmp = way;
	way = way->next;
	free(tmp);
	return (way);
}

int				conflict_solver(t_list **way_arr, t_data *s)
{
	if (!way_arr || !s)
		return (-1);
	if (find_ways(way_arr, s) < 0)
		return (-1);
	if (!(s->tail1 = cut_way1(way_arr, s->conflict_way2, s->conflict_way1, s)))
		return (-1);
	if (!(s->tail2 = cut_way2(way_arr, s->conflict_way2, s)))
		return (-1);
	its_alive(way_arr, s);
	renumber_way_array_len(way_arr, s);
	return (0);
}

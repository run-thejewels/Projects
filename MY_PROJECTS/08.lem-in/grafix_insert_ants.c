/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafix_insert_ants.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 13:43:56 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:42:19 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	insert_zero_ants(t_list *prev, t_list *next, t_data *s)
{
	t_list	*tmp;

	if (!prev || !next || !s)
		return ;
	if (!(tmp = ft_lstnew_fag(NULL, 0)))
		return ;
	prev->next = tmp;
	tmp->next = next;
	prev = tmp;
	if (!(tmp = ft_lstnew_fag(NULL, 0)))
		return ;
	prev->next = tmp;
	tmp->next = next;
}

void		insert_ants(t_list **ant_queues, t_data *s)
{
	short	i;
	t_list	*queue;
	t_list	*next;

	if (!ant_queues || !s)
		return ;
	i = 0;
	while (ant_queues[i])
	{
		queue = ant_queues[i];
		while (queue->next)
		{
			next = queue->next;
			insert_zero_ants(queue, next, s);
			queue = next;
		}
		i++;
	}
}

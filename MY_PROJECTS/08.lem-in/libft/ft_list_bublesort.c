/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bublesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 18:06:00 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/12 19:56:48 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_bsort_gotobegin(t_list *begin, t_list **cur_l, t_list **prev_l,
		t_list **nxt_l)
{
	*prev_l = NULL;
	*cur_l = begin;
	*nxt_l = (*cur_l)->next;
}

static void	ft_bsort_swap(t_list **prev_l, t_list **cur_l, t_list **nxt_l,
		t_list **begin)
{
	if (*prev_l)
	{
		(*prev_l)->next = *nxt_l;
		(*cur_l)->next = (*nxt_l)->next;
		(*nxt_l)->next = *cur_l;
		ft_bsort_gotobegin(*begin, cur_l, prev_l, nxt_l);
	}
	else
	{
		(*cur_l)->next = (*nxt_l)->next;
		(*nxt_l)->next = *cur_l;
		*begin = *nxt_l;
		ft_bsort_gotobegin(*begin, cur_l, prev_l, nxt_l);
	}
}

t_list		*ft_list_bublesort(t_list *begin_list, int (*f)(t_list *))
{
	t_list	*list;
	t_list	*prev_l;
	t_list	*next_l;

	ft_bsort_gotobegin(begin_list, &list, &prev_l, &next_l);
	while (next_l)
	{
		if (f(list))
			ft_bsort_swap(&prev_l, &list, &next_l, &begin_list);
		else
		{
			prev_l = list;
			list = list->next;
			next_l = list->next;
		}
	}
	return (begin_list);
}

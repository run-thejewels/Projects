/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_murgesort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:57:27 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/12 20:07:09 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_chlist_length(t_list *list)
{
	int		count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}

static void		ft_list_murgesort_split(t_list *begin_list, t_list **a,
		t_list **b)
{
	int		len;
	int		i;
	int		halflen;

	len = ft_chlist_length(begin_list);
	*a = begin_list;
	if (len < 2)
		*b = NULL;
	else
	{
		halflen = (len - 1) / 2;
		i = 0;
		*b = begin_list;
		while (i < halflen)
		{
			begin_list = begin_list->next;
			i++;
		}
		*b = begin_list->next;
		begin_list->next = NULL;
	}
}

static t_list	*ft_listmurgesort_murge(t_list *a, t_list *b,
		int (*f)(t_list *, t_list *))
{
	t_list	*dst;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (f(a, b))
	{
		dst = a;
		dst->next = ft_listmurgesort_murge(a->next, b, f);
	}
	else
	{
		dst = b;
		dst->next = ft_listmurgesort_murge(a, b->next, f);
	}
	return (dst);
}

void			ft_list_murgesort(t_list **begin_list,
		int (*f)(t_list *, t_list *))
{
	t_list	*a;
	t_list	*b;

	if (!begin_list || !(*begin_list) || !(*begin_list)->next)
		return ;
	ft_list_murgesort_split(*begin_list, &a, &b);
	ft_list_murgesort(&a, f);
	ft_list_murgesort(&b, f);
	*begin_list = ft_listmurgesort_murge(a, b, f);
}

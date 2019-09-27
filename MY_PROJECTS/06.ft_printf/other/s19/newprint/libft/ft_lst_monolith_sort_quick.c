/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_sort_quick.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:06:59 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/10 18:29:21 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		link_content_repair(t_list *begin, void *contents)
{
	size_t		size;

	size = begin->content_size;
	while (begin)
	{
		begin->content = contents;
		contents = ft_jump(contents, size);
		begin = begin->next;
	}
}

static void		link_repair(t_list *begin, size_t amount)
{
	t_list		*temp;
	size_t		index;

	index = 0;
	while (index != amount)
	{
		temp = (t_list *)ft_jump(begin, index * sizeof(t_list));
		temp->next = temp + sizeof(t_list);
		index++;
	}
	temp->next = NULL;
}

void			ft_lst_monolith_sort_quick(t_list *lst_mono, \
	int (*f)(void *, void *))
{
	size_t		amount;
	void		*temp;

	if (!lst_mono || !f)
		return ;
	amount = ft_lst_chain_len(lst_mono);
	if (amount == 1)
		return ;
	ft_sort_quick(lst_mono, sizeof(t_list), amount, f);
	link_repair(lst_mono, amount);
	temp = ft_lst_to_array_free(lst_mono);
	link_content_repair(lst_mono, temp);
}

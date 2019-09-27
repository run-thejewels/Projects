/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unfolding_arguments.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:13:58 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 19:44:31 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int	where_is_spaces(char *str)
{
	size_t	index;

	index = 0;
	while (str[index])
	{
		if (ft_isspace(str[index]))
			return (1);
		index++;
	}
	return (0);
}

static void	paste_arguments(t_list *lst, t_list *new)
{
	free(lst->content);
	if (ft_lst_chain_len(new) == 1)
	{
		lst->content = new->content;
		lst->content_size = new->content_size;
		free(new);
		return ;
	}
	lst->content = new->content;
	lst->content_size = new->content_size;
	(ft_lst_get_end(new))->next = lst->next;
	lst->next = new->next;
	free(new);
}

void		unfolding_arguments(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		if (where_is_spaces(lst->content))
		{
			temp = ft_lst_cut_numbers(lst->content);
			if (temp)
				paste_arguments(lst, temp);
		}
		lst = lst->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_keep_stacks.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:04:35 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/22 23:33:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_lst_stack_keep_stacks_clean_all(t_list ***stacks)
{
	t_list			*temp;
	t_list			*temp_2;

	temp = **stacks;
	while (temp)
	{
		ft_lst_free_chain((t_list *)temp->content);
		temp_2 = temp->next;
		free(temp);
		temp = temp_2;
	}
	free(*stacks);
	*stacks = NULL;
}

t_list				**ft_lst_stack_keep_stacks(int free_all)
{
	static t_list	**stacks;

	if (free_all)
	{
		ft_lst_stack_keep_stacks_clean_all(&stacks);
		return (NULL);
	}
	if (!stacks)
	{
		if (!(stacks = (t_list **)malloc(sizeof(t_list *))))
			return (NULL);
		*stacks = ft_lstnew_no_copy(NULL, 0);
	}
	return (stacks);
}

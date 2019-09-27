/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_deduplication.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:16:51 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/24 19:43:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_deduplication(t_list *orig)
{
	t_list	*new;
	t_list	*temp;

	if (!orig)
		return (NULL);
	temp = orig;
	new = NULL;
	while (orig)
	{
		if (!ft_lstsearch_content(new, orig->content, orig->content_size))
			ft_lstadd_to_end(&new, ft_lst_unit_transfer_with_malloc(orig));
		orig = orig->next;
	}
	ft_lst_free_chain(temp);
	return (new);
}

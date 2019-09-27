/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_cs_replace.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 23:50:07 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/29 00:11:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_cs_replace(t_list **lst, size_t cs)
{
	t_list	*temp;
	t_list	*result;

	if (!lst || !*lst)
		return (NULL);
	temp = *lst;
	if (temp->content_size == cs)
		return (temp);
	while (temp->next)
	{
		if ((temp->next)->content_size == cs)
		{
			result = temp->next;
			ft_lst_cut(&(temp->next), &temp);
			ft_lstadd(lst, result);
			return (result);
		}
		temp = temp->next;
	}
	return (NULL);
}

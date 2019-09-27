/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch_str_content.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 15:42:47 by ahalmon-          #+#    #+#             */
/*   Updated: 2018/12/25 15:47:12 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch_str_content(t_list *lst, char *to_search)
{
	t_list	*temp;

	if (!lst || !to_search)
		return (NULL);
	temp = lst;
	while (temp)
	{
		if (!ft_strcmp((char *)temp->content, to_search))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

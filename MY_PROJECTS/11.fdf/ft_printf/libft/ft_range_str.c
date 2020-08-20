/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 19:50:10 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/17 22:41:12 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*range_begin_str(t_list **lst, char *str)
{
	t_list			*temp;

	temp = *lst;
	while (temp)
	{
		if ((char *)temp->content == str)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew(NULL, 0);
	temp->content = (void *)str;
	ft_lstadd(lst, temp);
	return (temp);
}

char				ft_range_str(char *str)
{
	static t_list	*lst;
	t_list			*current;

	if (!str)
		return ('\0');
	if (!(current = range_begin_str(&lst, str)))
		return ('\0');
	if (str[current->content_size])
	{
		current->content_size++;
		return (str[current->content_size - 1]);
	}
	else
	{
		ft_lstdel_complite(&current, &lst);
		return ('\0');
	}
}

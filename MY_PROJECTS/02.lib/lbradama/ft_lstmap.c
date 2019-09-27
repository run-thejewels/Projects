/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 18:37:49 by kbethany          #+#    #+#             */
/*   Updated: 2019/01/07 18:37:04 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*a;
	t_list	*buf_a;

	if (lst == NULL || f == NULL)
		return (NULL);
	a = f(lst);
	buf_a = a;
	while (lst->next)
	{
		lst = lst->next;
		if (!(a->next = f(lst)))
		{
			free(a->next);
			return (NULL);
		}
		a = a->next;
	}
	return (buf_a);
}

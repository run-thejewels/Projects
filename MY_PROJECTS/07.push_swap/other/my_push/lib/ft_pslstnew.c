/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pslstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:43:38 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 11:40:36 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_plst			*ft_pslstnew(void)
{
	t_plst		*list;

	if (!(list = (t_plst*)malloc(sizeof(t_plst))))
		return (NULL);
	if (list != NULL)
	{
		list->len = 0;
		list->head = NULL;
		list->tail = NULL;
	}
	return (list);
}

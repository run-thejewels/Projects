/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:20:49 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:21:09 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_lstappend(t_plst *list, int v)
{
	t_node	*new;

	if (list != NULL)
	{
		if ((new = (t_node*)malloc(sizeof(t_node))) != NULL)
		{
			new->v = v;
			new->next = NULL;
			if (list->tail == NULL)
			{
				list->head = new;
				list->tail = new;
			}
			else
			{
				list->tail->next = new;
				list->tail = new;
			}
			list->len++;
		}
	}
	return (list);
}

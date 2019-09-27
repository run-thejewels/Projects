/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:24:52 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:25:14 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_push_a(t_plst *la, t_plst *lb, t_plst *mv)
{
	t_node	*tmp;

	if (lb->head == NULL)
		return (mv);
	else
	{
		tmp = lb->head;
		lb->head = lb->head->next;
		if (la->head != NULL)
			tmp->next = la->head;
		la->head = tmp;
		if (la->tail == NULL)
		{
			la->tail = tmp;
			la->tail->next = NULL;
		}
		else if (lb->head == NULL)
			lb->tail = NULL;
		la->len++;
		lb->len--;
	}
	return (mv = ft_lstappend(mv, 3));
}

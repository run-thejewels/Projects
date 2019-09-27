/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:23:26 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:23:50 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_push_b(t_plst *la, t_plst *lb, t_plst *mv)
{
	t_node	*tmp;

	if (la->head == NULL)
		return (mv);
	else
	{
		tmp = la->head;
		la->head = la->head->next;
		if (lb->head != NULL)
			tmp->next = lb->head;
		lb->head = tmp;
		if (lb->tail == NULL)
		{
			lb->tail = tmp;
			lb->tail->next = NULL;
		}
		else if (la->head == NULL)
			la->tail = NULL;
		lb->len++;
		la->len--;
	}
	return (mv = ft_lstappend(mv, 4));
}

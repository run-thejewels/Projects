/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_revrotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:27:23 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:27:46 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_revrotate(t_plst *l, t_plst *mv, int ab)
{
	t_node	*tmp;
	t_node	*tta;

	if (l->head == NULL || l->head == l->tail)
		return (mv);
	tmp = l->tail;
	tta = l->head;
	while (tta->next != tmp)
		tta = tta->next;
	l->tail = tta;
	l->tail->next = NULL;
	tmp->next = l->head;
	l->head = tmp;
	if (ab < 0)
		return (NULL);
	return (mv = ft_lstappend(mv, 8 + ab));
}

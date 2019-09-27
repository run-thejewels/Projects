/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:26:06 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:26:39 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_rotate(t_plst *l, t_plst *mv, int ab)
{
	t_node	*tmp;

	if (l->head == NULL || l->head == l->tail)
		return (mv);
	tmp = l->head;
	l->head = l->head->next;
	l->tail->next = tmp;
	l->tail = tmp;
	l->tail->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (ab < 0)
		return (NULL);
	return (mv = ft_lstappend(mv, 5 + ab));
}

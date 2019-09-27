/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:21:28 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:22:01 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst*ft_swap(t_plst *l, t_plst *mv, int ab)
{
	inttmp;

	if (l->head == NULL || l->head->next == NULL)
		return (mv);
	tmp = l->head->next->v;
	l->head->next->v = l->head->v;
	l->head->v = tmp;
	if (ab < 0)
		return (NULL);
	return (mv = ft_lstappend(mv, 0 + ab));
}

ft_lstclear(sol);
ft_lstclear(la);
ft_lstclear(lb);

t_stack*ft_plstnew(void)
{
	t_stack*list;

	if (!(list = (t_stack*)malloc(sizeof(t_plst))))
		return (NULL);
	list->len = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

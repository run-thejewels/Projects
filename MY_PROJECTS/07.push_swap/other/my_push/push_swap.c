/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 20:18:23 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/09 20:18:35 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** These functions are our basic moves: reverse rotate, rotate, push a, push b
** and swap. With these we have to sort n random int arguments.
*/

t_plst			*ft_revrotate(t_plst *l, t_plst *mv, int ab)
{
	t_node		*tmp;
	t_node		*tta;

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

t_plst			*ft_rotate(t_plst *l, t_plst *mv, int ab)
{
	t_node		*tmp;

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

t_plst			*ft_push_a(t_plst *la, t_plst *lb, t_plst *mv)
{
	t_node		*tmp;

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

t_plst			*ft_push_b(t_plst *la, t_plst *lb, t_plst *mv)
{
	t_node		*tmp;

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

t_plst			*ft_swap(t_plst *l, t_plst *mv, int ab)
{
	int			tmp;

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

t_stack			*ft_plstnew(void)
{
	t_stack		*list;

	if (!(list = (t_stack*)malloc(sizeof(t_plst))))
		return (NULL);
	list->len = 0;
	list->head = NULL;
	list->tail = NULL;
	return (list);
}

t_plst			*ft_lstappend(t_plst *list, int v)
{
	t_node		*new;

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

t_plst		*ft_choose(t_plst *la, t_plst *lb, t_plst *sol)
{
	t_plst	*cur;

	cur = ft_pslstnew();
	if (ft_issortasc(la))
	{
		if (la->len < 20)
		{
			cur = ft_dyn_resolve(la);
			ft_dyn_copy(cur, sol);
			ft_lstdelallnodes(cur);
		}
		cur = ft_sortmin(la, lb, cur);
		if (sol->head != NULL && cur->len < sol->len)
			ft_dyn_copy(cur, sol);
		else if (sol->head == NULL)
			ft_dyn_copy(cur, sol);
		ft_lstdelallnodes(cur);
	}
	free(cur);
	return (sol);
}

const static char	*g_push_swap_moves[11] = { "sa", "sb", "ss", "pa", "pb",
	"ra", "rb", "rr", "rra", "rrb", "rrr" };

void				ft_display_color(t_plst *mv)
{
	t_node			*tmp;
	int				len;
	int				col;

	tmp = mv->head;
	col = 31;
	while (tmp)
	{
		ft_printf("\x1b[%dm%s\x1b[0m", col, g_push_swap_moves[tmp->v]);
		if (len < mv->len - 1)
			ft_printf(" ");
		tmp = tmp->next;
		len++;
		col++;
		if (col == 38)
			col = 31;
	}
}

void				ft_display(t_plst *mv, int bonus)
{
	t_node			*tmp;
	int				len;

	if (mv->head == NULL)
		return ;
	tmp = mv->head;
	len = 0;
	if (bonus == 2)
		ft_display_color(mv);
	else
	{
		while (tmp)
		{
			ft_printf(g_push_swap_moves[tmp->v]);
			if (len < mv->len - 1)
				ft_printf(" ");
			tmp = tmp->next;
			len++;
		}
	}
	ft_printf("\n");
	if (bonus == 1)
		ft_printf("\nNombre de coups : %d\n", len);
}


int main(int ac, char **av)
{
  t_stack *la;
  t_stack *lb;
  t_stack	*sol;

	sol = ft_plstnew();
	if (ac == 1)
		return (0);
	la = ft_parsing(ac, av);
	lb = ft_pslstnew();
	ft_choose(la, lb, sol);
	ft_display(sol, bonus);
	return (0);
}

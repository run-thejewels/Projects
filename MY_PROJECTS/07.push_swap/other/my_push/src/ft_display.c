/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 17:16:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 11:37:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
** Here, we display whatever based on a list of moves.
*/

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

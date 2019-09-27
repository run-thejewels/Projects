/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:17:13 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:17:48 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_display(t_plst *mv, int bonus)
{
	t_node	*tmp;
	int		len;

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonusdisplaystack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:59:20 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/27 09:45:35 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		ft_print_l(t_plst *l, char *str)
{
	t_node	*tmp;

	tmp = l->head;
	ft_printf("%s |", str);
	while (tmp)
	{
		ft_printf("%7d", tmp->v);
		tmp = tmp->next;
	}
	ft_printf("|\n");
}

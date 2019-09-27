/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:53:44 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/24 16:07:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	display_stat(t_stack *l)
{
	int	i;

	i = 0;
	ft_printf("=======================================\n");
	ft_printf("Elements: %d\n Max: %d\n Min: %d\n", l->ia, l->max, l->min);
	ft_printf("\nA: ");
	while (i < list->ia)
	{
		ft_printf(" % d", list->va[i]);
		i++;
	}
	i = 0;
	ft_printf("\nB: ");
	while (i < list->ib)
	{
		ft_printf(" % d", list->vb[i]);
		i++;
	}
	ft_printf("\n=======================================\n");
}

void	display_com(t_stack *list, char* a)
{
	int	i;

	i = 0;
	ft_printf("\n=======================================\n");
	ft_printf("com: %s\n", a);
	ft_printf("elm: %d\n", list->ia);
	ft_printf("\nA: ");
	while (i < list->ia)
	{
		ft_printf(" % d", list->va[i]);
		i++;
	}
	i = 0;
	ft_printf("\nB: ");
	while (i < list->ib)
	{
		ft_printf(" % d", list->vb[i]);
		i++;
	}
	ft_printf("\n=======================================\n");
}

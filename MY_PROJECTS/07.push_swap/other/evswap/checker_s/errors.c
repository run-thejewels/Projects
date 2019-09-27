/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:08:40 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/20 22:08:43 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void error_lst(t_list *lst)
{
	ft_lst_free_chain(lst);
	ft_putstr_fd("KO\n", 2);
	exit(1);
}

void error_input(void)
{
	ft_putstr_fd("KO\n", 2);
	exit(1);
}

void error_operators(t_list *lst, t_stacks *stacks)
{
	ft_lst_free_chain(lst);
	ft_putstr_fd("KO\n", 2);
	out(stacks);
	exit(1);
}

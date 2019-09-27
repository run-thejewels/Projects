/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_ps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:08:40 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/20 22:08:43 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

void error_lst_ps(t_list *lst)
{
	ft_lst_free_chain(lst);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void error_input_ps(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

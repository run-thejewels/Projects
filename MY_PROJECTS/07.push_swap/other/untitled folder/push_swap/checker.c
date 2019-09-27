/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:38:52 by kbethany          #+#    #+#             */
/*   Updated: 2019/08/21 17:41:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	if_oper(t_stack *l, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		pusha(l);
	if (!ft_strcmp(str, "pb\n"))
		pushb(l);
	if (!ft_strcmp(str, "ra\n"))
		rotate(l, 'a');
	if (!ft_strcmp(str, "rb\n"))
		rotate(l, 'b');
	if (!ft_strcmp(str, "rr\n"))
	{
		rotate(l, 'a');
		rotate(l, 'b');
	}
	if (!ft_strcmp(str, "sa\n"))
		swap(l, 'a');
	if (!ft_strcmp(str, "sb\n"))
		swap(l, 'a');
	if (!ft_strcmp(str, "ss\n"))
	{
		swap(l, 'a');
		swap(l, 'b');
	}
}

int			main(int c, char **v)
{
	t_stack	*l;
	char	*str;

	str = NULL;
	l = ft_parsing(c, v);
	if (ac < 2)
		return (0);
	while ((get_next_line(0, &str) == 1))
	{
		if_oper(l, str);
		if (!ft_strcmp(str, "rra\n"))
			rrotate(l, 'a');
		if (!ft_strcmp(str, "rrb\n"))
			rrotate(l, 'b');
		if (!ft_strcmp(str, "rrr\n"))
		{
			rrotate(l, 'a');
			rrotate(l, 'b');
		}
		free(str);
	}
	if (ideal(l))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (0);
}

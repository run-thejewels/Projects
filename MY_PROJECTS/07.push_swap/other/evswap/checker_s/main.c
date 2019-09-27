/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:10:20 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/20 22:10:22 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

int main(int argc, char **argv)
{
	t_list *arguments;
	t_stacks stacks;
	t_list *operators;

	if (!(arguments = ft_get_arguments_command_line(argc, argv)))
		error_input();
	if (!prove_letters(arguments))
		error_lst(arguments);
	unfolding_arguments(arguments);
	if (!prove_arguments(&arguments) || !structure_filler(arguments, &stacks))
		error_lst(arguments);
	operators = get_operators();
	if (!prove_operators(operators))
		error_operators(operators, &stacks);
	algorithm(&stacks, operators);
	out(&stacks);
	return (0);
}

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
	t_flaggs flags;

	if (!(arguments = ft_get_arguments_command_line(argc, argv)))
		error_input_ps();
	arguments = flags_filler(arguments, &flags);
	if (!prove_letters(arguments))
		error_lst_ps(arguments);
	unfolding_arguments(arguments);
	if (!prove_arguments(&arguments) || !structure_filler_ps(arguments, &stacks))
		error_lst_ps(arguments);
	print_begin(&stacks, &flags);
	algorithm_ps(&stacks, &flags);
	out(&stacks);
	return (0);
}

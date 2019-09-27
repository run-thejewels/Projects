/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:16:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:16:40 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_stack *la;
	t_stack *lb;
	t_stack*sol;

	sol = ft_plstnew();
	if (ac == 1)
		return (0);
	la = ft_parsing(ac, av);
	lb = ft_pslstnew();
	ft_choose(la, lb, sol);
	ft_display(sol, bonus);
	return (0);
}

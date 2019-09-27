/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:45:27 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/08 14:14:05 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_map_valid(argv[i]))
			{
				ft_map_print(ft_bsq_put(argv[i]));
				ft_putstr("\n");
			}
			else
				ft_putstr("aucune\n");
		}
	}
	else
			;
} 

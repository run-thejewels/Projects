/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:45:27 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 17:08:54 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		main(int argc, char **argv)
{
	int			i;
	int			fd;

	i = 1;
	if (argc == 1)
		ft_map_read_and_print(0);
	else
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			ft_map_read_and_print(fd);
			i++;
		}
	}
	return (0);
}

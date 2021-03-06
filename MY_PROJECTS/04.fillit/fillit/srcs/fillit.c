/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:32:57 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/01 13:40:35 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_error(1);
		ft_input(fd);
		if (close(fd) < 0)
			ft_error(2);
	}
	else
		ft_putstr("usage: fillit source_file\n");
	return (1);
}

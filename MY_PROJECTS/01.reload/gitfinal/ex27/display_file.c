/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:14:12 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/29 16:23:45 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void	display(char *fname)
{
	int		d;
	char	*buf;

	d = open(fname, O_RDONLY);
	if (d < 0)
		return ;
	while (read(d, &buf, 1))
		write(1, &buf, 1);
	close(d);
}

int		main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else if (ac == 2)
		display(av[1]);
	return (0);
}

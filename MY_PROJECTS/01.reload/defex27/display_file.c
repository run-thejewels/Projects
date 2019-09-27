/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 17:14:12 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/26 18:53:25 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

int main(int ac, char **av)
{
	char	buf[BUFFER_SIZE];
	int		d;
	int 	r;


	if (ac == 1)
		write(2, "File name missing.", 20);
	else if (ac > 2)
		write(2, "too many arguments.",20);
	else if (ac == 2)
	{
		d  = open(av[1], O_RDONLY);
		if (d == -1)
			write(1, "No file\n", 8);
		else
		{
			while ((r = read(d, buf, BUFFER_SIZE)))
			{
				buf[r] = '\0';
				ft_putstr(buf);
			}
		}
	}
	return (0);
}
		

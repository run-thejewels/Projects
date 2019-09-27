/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gmain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 18:40:12 by kbethany          #+#    #+#             */
/*   Updated: 2018/10/08 20:57:14 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUFFER_SIZE 4096

void    ft_putchar(char a)
{
    write(1, &a, 1);
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
        i++;
	return (i);
}

int main(int ac,char **av)
{
    int i;
	int	j;
    int fd;
	int h;
    int r;
    char    **map;
	char	**map2;
    char    a;
    char    buffer[BUFFER_SIZE][BUFFER_SIZE];
	char	empty;
	char	obstacle;
	char	full;


    if (ac < 2)
        return (0);
    i = 1;
	j =0;
    a = '\n';
	r = 0;
	h = 0;
	empty = 0;
	obstacle = 0;
	full = 0;
	map2 = 0;
    while (i < ac)
    {
		r = ft_strlen(av[i]);
		map = (char**)malloc(r);
        fd = open(av[i], O_RDONLY);
        if (fd != -1)
            while ((r = read(fd, buffer, BUFFER_SIZE)))
				map = buffer;
        close(fd);
		i++;
    }
	r = 0;
	i = 0;
	while (**map != '\n')
	{
		if ( '0' <= map[i][j] && map[i][j] <= '9')
			h = (h * 10) + map [i][j];
		else if (empty == 0)
			empty = map[i][j];
		else if (obstacle == 0)
			obstacle = map[i][j];
		else if (full == 0)
			full = map[i][j];
		j++;
	}
	i = 1;
	while (map)
	{
		map2[i - 1][j] = map[i][j];
		if (map[i][j] == '\n')
		{
			j = 0;
			i++;
		}
		j++;
	}
	r = strlen(map2[1]);	
    return (0);
}

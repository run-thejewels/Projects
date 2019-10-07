/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:49:39 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 17:54:11 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		read_ants(t_data *s)
{
	char	*tmp;
	int		ret;

	if (!s)
		return (0);
	while (gnl(0, &(s->line)) && (s->line)[0] == '#' && \
			!ft_strcmp(s->line, "##start") && !ft_strcmp(s->line, "##end"))
		ft_strdel(&(s->line));
	if (!(s->line))
		return (0);
	s->ants = ft_atoi(s->line);
	tmp = ft_itoa(s->ants);
	ret = ft_strcmp(tmp, s->line);
	ft_strdel(&tmp);
	ft_strdel(&(s->line));
	fprint_fd(s->fd, "ants number = %d\n", s->ants);
	if (ret != 0 || s->ants < 1)
	{
		fprint_fd(s->fd, "invalid line with ants\n");
		return (0);
	}
	ft_strdel(&(s->line));
	return (1);
}

static void		check_flags(int ac, char **av, t_data *s)
{
	int		i;

	if (!av || !s || ac < 2)
		return ;
	i = 1;
	while (i < ac)
	{
		if (!ft_strcmp(av[i], "-error"))
			s->err_flag_on = 1;
		if (!ft_strcmp(av[i], "-grafix"))
			s->grafix_on = 1;
		if (!ft_strcmp(av[i], "-logs"))
			s->full_logs_on = 1;
		i++;
	}
}

static t_room	*read_input(int ac, char **av, t_data *s)
{
	t_room	*room;

	if (!s || !av)
		free_exit(NULL, s, 0, "empty pointer");
	ft_bzero(s, sizeof(t_data));
	check_flags(ac, av, s);
	if ((s->fd = open("log.txt", O_RDWR | O_CREAT)) < 1)
		free_exit(NULL, s, 1, "cant open file log.txt");
	if (!read_ants(s))
		free_exit(NULL, s, 1, "read_ants");
	if (!(room = read_rooms(s)))
		free_exit(NULL, s, 1, "read rooms incorrect");
	make_linkage(room, s);
	return (room);
}

void			close_all(t_list **ant_queues, t_list **way_arr, t_room *room, \
		t_data *s)
{
	if (ant_queues)
		kill_tlist_array(ant_queues, 0);
	if (way_arr)
		kill_tlist_array(way_arr, 1);
	if (room)
		kill_roomlist(room);
	if (s)
	{
		if (s->full_logs_on)
			fprint("number of steps = %d\n", s->steps);
		fprint_fd(s->fd, "number of lines = %d", s->steps);
		if (s->line)
			ft_strdel(&(s->line));
		close(s->fd);
		free(s);
	}
}

int				main(int ac, char **av)
{
	t_data	*s;

	if (!(s = (t_data *)malloc(sizeof(t_data))))
		return (-1);
	if (!(s->room = read_input(ac, av, s)))
		free_exit(s->room, s, 1, "error on input");
	if (!(s->way_arr = karpov_globchansky(s->room, s)) || !(s->way_arr[0]))
		free_exit(s->room, s, 0, "no ways");
	temp_print_roomlist(s->room, s);
	print_all_ways(s->way_arr, s);
	if (!(s->ant_queues = prepare_ant_queues(s->way_arr, s)))
	{
		kill_tlist_array(s->way_arr, 1);
		free_exit(s->room, s, 0, "problem with ant queues");
	}
	if (s->grafix_on)
		grafix(s);
	else
		print_ant_queues(s->way_arr, s->ant_queues, s);
	close_all(s->ant_queues, s->way_arr, s->room, s);
	return (0);
}

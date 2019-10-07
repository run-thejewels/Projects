/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_linkage_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:47:14 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/03 11:01:50 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_line(t_room *room, t_data *s)
{
	if (!s || !room || !s->line)
		free_exit(room, s, 1, "make_linkage - empty pointer");
	if (!strcmp("##start", s->line) || !strcmp("##end", s->line))
		free_exit(room, s, 1, "make linkage - start / end in linkage!");
	if (s->line[0] == '#')
		return (0);
	return (1);
}

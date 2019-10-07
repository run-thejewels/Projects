/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 16:11:16 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 16:22:45 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	teleport_ants(t_room *room, t_data *s)
{
	int		ant_nbr;

	if (!room || !s)
		return ;
	ant_nbr = 1;
	while (ant_nbr <= s->ants)
	{
		fprint("L%d-%s ", ant_nbr, room->name);
		ant_nbr++;
	}
	fprint("\n");
	s->steps = 1;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 13:51:25 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 17:09:45 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char		*find_room_name(char *src, short *name_len)
{
	char	*name;
	short	len;
	short	i;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len] && src[len] != ' ' && len < 30000)
		len++;
	if (len >= 30000)
		return (NULL);
	if (!(name = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
		name[i] = src[i];
	name[i] = '\0';
	*name_len = len;
	return (name);
}

static int		find_room_position(t_room *room, char *src, short name_len)
{
	short	i;

	if (!room || !src || name_len < 1)
		return (0);
	i = name_len;
	while (src[i] && i < 30000 && (src[i] < '0' || src[i] > '9'))
		i++;
	if (src[i] == '\0' || i >= 100)
		return (0);
	room->pos.hor = ft_atoi(&(src[i]));
	while (src[i] && i < 30000 && src[i] != ' ')
		i++;
	while (src[i] && i < 30000 && (src[i] < '0' || src[i] > '9'))
		i++;
	if (src[i] == '\0' || i >= 30000)
		return (0);
	room->pos.vert = ft_atoi(&(src[i]));
	return (1);
}

static void		line_validation(t_room **room, char **src_string)
{
	t_room	*tmp;
	char	*str;
	size_t	size;

	tmp = *room;
	size = ft_strlen(tmp->name) + 2;
	if (!(str = ft_itoa(tmp->pos.hor)))
		return ;
	size = size + ft_strlen(str);
	free(str);
	if (!(str = ft_itoa(tmp->pos.vert)))
		return ;
	size = size + ft_strlen(str);
	free(str);
	if (size != ft_strlen(*src_string))
		kill_room(room);
	ft_strdel(src_string);
}

t_room			*new_room(char **src_string, short room_flag)
{
	t_room	*dst;
	short	name_len;

	if (!src_string || !(src_string))
		return (NULL);
	if (!(dst = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	ft_bzero(dst, sizeof(t_room));
	dst->room_flag = room_flag;
	if (!(dst->name = find_room_name(*src_string, &name_len)))
	{
		kill_room(&dst);
		ft_strdel(src_string);
		return (NULL);
	}
	if (!(find_room_position(dst, *src_string, name_len)))
	{
		kill_room(&dst);
		ft_strdel(src_string);
		return (NULL);
	}
	line_validation(&dst, src_string);
	return (dst);
}

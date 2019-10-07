/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_way_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 16:45:30 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:47:02 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*cpy_node(t_room *src, int cont_size)
{
	t_list	*dst;
	t_room	*room;

	if (!src)
		return (NULL);
	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(room = (t_room *)malloc(sizeof(t_room))))
	{
		free(dst);
		return (NULL);
	}
	*room = *src;
	if (!(room->name = ft_strdup(src->name)))
	{
		free(dst);
		return (NULL);
	}
	dst->content_size = cont_size;
	dst->content = room;
	return (dst);
}

static t_list	*cpy_way(t_list *src)
{
	t_list	*dst;
	t_list	*lst;

	if (!src)
		return (NULL);
	if (!(dst = cpy_node(src->content, src->content_size)))
		return (NULL);
	lst = dst;
	src = src->next;
	while (src)
	{
		if (!(lst->next = cpy_node(src->content, src->content_size)))
		{
			kill_tlist(dst, 1);
			return (NULL);
		}
		lst = lst->next;
		src = src->next;
	}
	lst->next = NULL;
	return (dst);
}

t_list			**cpy_way_arr(t_list **src, t_list **to_delete, t_data *s)
{
	t_list	**dst;
	short	size;
	short	i;

	kill_tlist_array(to_delete, 1);
	if (!src || !s)
		return (NULL);
	size = 0;
	while (src[size])
		size++;
	if (!(dst = (t_list **)malloc(sizeof(t_list *) * (size + 1))))
		return (NULL);
	dst[size] = NULL;
	i = 0;
	while (src[i])
	{
		if (!(dst[i] = cpy_way(src[i])))
		{
			kill_tlist_array(dst, 1);
			return (NULL);
		}
		i++;
	}
	return (dst);
}

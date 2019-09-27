/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 21:05:47 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/04 23:59:09 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list		*search_lst(t_list *lst, int fd, int *i)
{
	t_list			*temp;

	temp = lst;
	*i = 1;
	while (temp)
	{
		if ((int)(temp->content_size) == fd)
		{
			if (temp->content)
				return (temp);
		}
		temp = temp->next;
	}
	return (NULL);
}

static char			*adder(t_list **lst, int fd, t_iter *i)
{
	t_list			*temp;

	i->work = 0;
	i->in = 0;
	i->chr = NULL;
	i->lst = NULL;
	temp = *lst;
	while (temp)
	{
		if ((int)(temp->content_size) == fd)
		{
			if (temp->content)
				return ((char *)(temp->content));
		}
		temp = temp->next;
	}
	temp = ft_lstnew("", 1);
	temp->content_size = (size_t)fd;
	ft_lstadd(lst, temp);
	return ((char *)(temp->content));
}

static void			joiner(char *buf, t_iter *i)
{
	i->work = 1;
	buf[i->in] = '\0';
	ft_lstadd(&(i->l), ft_lst_strnew(buf));
}

static char			*convert(char *old, t_list *lst, t_iter *i)
{
	size_t			index;
	char			*new;
	char			*residue;

	index = 0;
	while (old[index] && old[index] != '\n')
		index++;
	if (!(new = ft_strnew_not_bzero(index)))
		return (NULL);
	ft_memcpy(new, old, index);
	residue = ft_strdup((ft_strchr(old, '\n') + 1));
	free(old);
	lst->content = residue;
	i->work = 1;
	return (new);
}

int					get_next_line(const int fd, char **line)
{
	static t_iter	i;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	i.s = adder(&i.lst, fd, &i);
	while ((i.in = read(fd, buf, BUFF_SIZE)) > 0)
	{
		joiner(buf, &i);
		if (ft_strchr(i.s, '\n') || i.in < BUFF_SIZE)
		{
			i.s = ft_strjoin_fr_both(i.s, ft_lst_strjoin_fr(ft_lst_turn(i.l)));
			break ;
		}
	}
	if (!(i.chr = ft_strchr(i.s, '\n')) && i.in < BUFF_SIZE)
		(search_lst(i.lst, fd, &i.work))->content_size = -1;
	if (i.in < BUFF_SIZE && !ft_strlen(i.s))
		return (0);
	if (i.chr)
		i.s = convert(i.s, search_lst(i.lst, fd, &i.work), &i);
	if (!i.work)
		(search_lst(i.lst, fd, &i.work))->content_size = -1;
	*line = i.s;
	return (1);
}

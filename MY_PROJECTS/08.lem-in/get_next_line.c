/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:10:45 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/06/27 16:45:17 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*ft_create_list(void *ptr, size_t fd)
{
	t_list		*dst;

	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	dst->content = ptr;
	dst->content_size = fd;
	dst->next = NULL;
	return (dst);
}

static t_list	*ft_get_lst(size_t fd, t_list **head)
{
	t_list		*lst;

	if (!head)
		return (NULL);
	if (!(*head))
	{
		*head = ft_create_list(NULL, fd);
		return (*head);
	}
	lst = *head;
	while (lst->next && lst->content_size != fd)
		lst = lst->next;
	if (lst->content_size == fd)
		return (lst);
	if (!(lst->next = ft_create_list(NULL, fd)))
		return (NULL);
	lst = lst->next;
	return (lst);
}

static int		ft_new_line(t_list *lst, char **line, int fd, int ret)
{
	char		*tmp;
	int			len;

	len = 0;
	tmp = lst->content;
	while (tmp[len] != '\n' && tmp[len] != '\0')
		len++;
	if (tmp[len] == '\n')
	{
		*line = ft_strsub(lst->content, 0, len);
		tmp = ft_strdup(tmp + len + 1);
		free(lst->content);
		lst->content = tmp;
		if (tmp[0] == '\0')
			ft_strdel((char **)&(lst->content));
	}
	else if (tmp[len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(lst->content);
		ft_strdel((char **)&(lst->content));
		lst->content = NULL;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*lst;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || !(lst = ft_get_lst((size_t)fd, &head)))
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (lst->content == NULL)
			lst->content = ft_strnew(0);
		tmp = ft_strjoin(lst->content, buf);
		free(lst->content);
		lst->content = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	tmp = lst->content;
	if (ret < 0)
		return (-1);
	else if (ret == 0 && ((lst->content == NULL) || (tmp[0] == '\0')))
		return (0);
	return (ft_new_line(lst, line, fd, ret));
}

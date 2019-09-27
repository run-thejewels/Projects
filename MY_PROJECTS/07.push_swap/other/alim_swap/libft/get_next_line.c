/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:08:21 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/30 15:38:42 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_gnl		*get_list(t_gnl **alst, int fd)
{
	t_gnl				*temp;

	temp = *alst;
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	if (!(temp = (t_gnl *)malloc(sizeof(t_gnl))))
		return (NULL);
	if (!(temp->content = ft_strdup("")))
	{
		free(temp);
		return (NULL);
	}
	else
		temp->fd = fd;
	temp->next = *alst;
	*alst = temp;
	return (temp);
}

static void			del_list(t_gnl **alst, int fd)
{
	t_gnl				*victim;
	t_gnl				**buffer;

	buffer = alst;
	while (*buffer)
	{
		if ((*buffer)->fd == fd)
		{
			victim = *buffer;
			*buffer = victim->next;
			if (victim->content)
				free(victim->content);
			free(victim);
		}
		else
			buffer = &((*buffer)->next);
	}
}

static char			*join_buff_to_list(t_gnl *list, char *buff,
		t_gnl **alst, int fd)
{
	char				*temp;

	temp = list->content;
	if (!(list->content = ft_strjoin(temp, buff)))
		del_list(alst, fd);
	free(temp);
	return (list->content);
}

static char			*copy_tail_to_list(t_gnl *list, t_gnl **alst, int fd)
{
	char				*temp;

	if (ft_strchr(list->content, '\n'))
	{
		temp = list->content;
		if (!(list->content = ft_strdup(ft_strchr(temp, '\n') + 1)))
			del_list(alst, fd);
		free(temp);
	}
	return (list->content);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl		*alst;
	t_gnl				*list;
	int					num_bytes;
	char				buff[BUFF_SIZE + 1];

	CHERROR(fd, line, read(fd, buff, 0));
	CHECK((list = get_list(&alst, fd)));
	while (((num_bytes = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[num_bytes] = '\0';
		CHECK((list->content = join_buff_to_list(list, buff, &alst, fd)));
		if ((ft_strchr(buff, '\n')))
			break ;
	}
	if (num_bytes < BUFF_SIZE && ft_strlen(list->content) == 0)
	{
		del_list(&alst, fd);
		return (0);
	}
	CHECK((*line = ft_strchrdup(list->content, '\n')));
	CHECK((list->content = copy_tail_to_list(list, &alst, fd)));
	return (1);
}

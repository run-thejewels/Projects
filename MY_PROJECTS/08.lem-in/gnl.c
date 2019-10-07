/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 14:13:08 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/10/06 15:46:35 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_find_line(char **str_read, char **line)
{
	char *tmp;

	if ((*str_read)[0] == '\0')
	{
		ft_strdel(str_read);
		return (0);
	}
	if (ft_strchr(*str_read, '\n') != NULL)
	{
		*(ft_strchr(*str_read, '\n')) = '\0';
		*line = ft_strdup(*str_read);
		tmp = ft_strdup(ft_strchr(*str_read, '\0') + 1);
		free(*str_read);
		if (tmp)
		{
			*str_read = ft_strdup(tmp);
			free(tmp);
		}
	}
	else
	{
		*line = ft_strdup(*str_read);
		ft_memdel((void **)str_read);
	}
	return (1);
}

int			gnl(int const fd, char **line)
{
	static char	*str[FD_LIMIT];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			des;

	if (fd < 0 || fd > FD_LIMIT || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(str[fd]))
		str[fd] = ft_strnew(0);
	while (ft_strchr(str[fd], '\n') == NULL)
	{
		des = read(fd, buf, BUFF_SIZE);
		buf[des] = '\0';
		if (des == 0)
			break ;
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		if (!(str[fd]))
			str[fd] = ft_strnew(0);
		free(tmp);
	}
	return (ft_find_line(&str[fd], line));
}

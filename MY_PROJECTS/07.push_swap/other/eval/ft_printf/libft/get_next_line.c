/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 13:36:51 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/26 14:45:49 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_line(char **c, int ret, int fd, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (c[fd][len] != '\0' && c[fd][len] != '\n')
		len++;
	if (c[fd][len] == '\n')
	{
		*line = ft_strsub(c[fd], 0, len);
		tmp = ft_strdup(c[fd] + len + 1);
		free(c[fd]);
		c[fd] = tmp;
		if (c[fd][0] == '\0')
			ft_strdel(&c[fd]);
	}
	else if (c[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(c[fd]);
		ft_strdel(&c[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*c[255];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd == -1 || line == NULL)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (c[fd] == NULL)
			c[fd] = ft_strnew(1);
		tmp = ft_strjoin(c[fd], buf);
		free(c[fd]);
		c[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret == -1)
		return (-1);
	else if (ret == 0 && (c[fd] == NULL || c[fd][0] == '\0'))
		return (0);
	return (ft_line(c, ret, fd, line));
}

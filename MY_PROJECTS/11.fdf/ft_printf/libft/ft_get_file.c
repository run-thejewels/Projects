/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:11:42 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:07:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_get_file(char *path, size_t *size)
{
	int		re;
	int		fd;
	char	buf[BUFF_SIZE];
	t_list	*lst;

	*size = 0;
	if (!(fd = ft_open_file_readonly(path)) \
	|| BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (NULL);
	lst = NULL;
	while ((re = read(fd, buf, BUFF_SIZE)) > 0)
	{
		*size += (size_t)re;
		ft_lstadd(&lst, ft_lstnew((void *)buf, (size_t)re));
	}
	close(fd);
	return (ft_lst_to_array_free(ft_lst_turn(lst)));
}

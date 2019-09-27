/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_first_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 23:13:58 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/10 16:27:54 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_get_first_line(int fd)
{
	char	*first_line;
	int		ret;
	char	buf;

	first_line = (char *)(malloc(sizeof(char)));
	first_line[0] = '\0';
	while ((ret = read(fd, &buf, 1)) > 0)
	{
		if (buf == '\n')
			break ;
		first_line = ft_map_concat(first_line, buf);
	}
	return (first_line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file_readonly.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 19:14:26 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:04:18 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_open_file_readonly(char *path)
{
	int		fd;

	if (!path)
		return (0);
	fd = open(path, O_RDONLY);
	if (fd > 0)
		return (fd);
	return (0);
}

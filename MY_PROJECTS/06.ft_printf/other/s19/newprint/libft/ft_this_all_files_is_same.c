/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this_all_files_is_same.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:28:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:29:40 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_this_all_files_is_same(t_list *files)
{
	t_list	*first;
	t_list	*temp;

	if (!files)
		return (0);
	first = files;
	while (files)
	{
		temp = first;
		while (temp)
		{
			if (files->content_size != temp->content_size)
				return (0);
			if (ft_memcmp(files->content, temp->content, temp->content_size))
				return (0);
			temp = temp->next;
		}
		files = files->next;
	}
	return (1);
}

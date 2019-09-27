/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:38:54 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:40:45 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_get_all_files(t_list *paths)
{
	t_list	*result;
	t_list	*new;
	size_t	size;

	if (!paths)
		return (NULL);
	result = NULL;
	while (paths)
	{
		if (paths->content)
		{
			if (!(new = ft_lstnew_no_copy(ft_get_file(paths->content, \
				&size), size)))
			{
				ft_lst_free_chain(result);
				return (NULL);
			}
			ft_lstadd(&result, new);
		}
		paths = paths->next;
	}
	result = ft_lst_turn(result);
	return (result);
}

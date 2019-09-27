/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_all_content_size.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 23:18:36 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:06:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_all_content_size(t_list *lst)
{
	size_t	result;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		if (lst->content)
			result += lst->content_size;
		lst = lst->next;
	}
	return (result);
}

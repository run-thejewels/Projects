/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_free_cs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:28:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:36:54 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_putstr_free_cs(t_list *lst)
{
	char	*str;
	size_t	str_size;
	size_t	size;

	if (!lst)
		return (0);
	if (!(str = ft_lst_strjoin_counter_out_free_cs(lst, &str_size)))
	{
		size = 0;
		while (lst)
		{
			if (lst->content && lst->content_size)
			{
				ft_putstr_len(lst->content, lst->content_size);
				size += lst->content_size;
			}
			lst = lst->next;
		}
		return (size);
	}
	ft_putstr_len(str, str_size);
	free(str);
	return (str_size);
}

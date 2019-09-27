/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:17:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:51:49 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_putstr_free(t_list *lst)
{
	char	*str;
	size_t	str_size;
	size_t	size;

	if (!(str = ft_lst_strjoin_counter_out_free(lst, &str_size)))
	{
		size = 0;
		while (lst)
		{
			str_size = ft_strlen_safe(lst->content);
			if (lst->content && str_size)
			{
				ft_putstr_len(str, str_size);
				size += str_size;
			}
			lst = lst->next;
		}
		return (size);
	}
	ft_putstr_len(str, str_size);
	free(str);
	return (str_size);
}

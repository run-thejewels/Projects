/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr_sep.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:41:37 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:41:53 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_putstr_sep_free_put2(char *str, size_t size)
{
	ft_putstr_len(str, size);
	return (size);
}

size_t		ft_lst_putstr_sep(t_list *lst, char *separator)
{
	char	*str;
	size_t	str_size;
	size_t	size;
	size_t	sep_len;

	sep_len = ft_strlen_safe(separator);
	if (!(str = ft_lst_strjoin_sep_counter_out(lst, separator, &str_size)))
	{
		size = 0;
		while (lst)
		{
			str_size = ft_strlen_safe(lst->content);
			if (lst->content && str_size)
			{
				ft_putstr_len(lst->content, str_size);
				size += str_size;
				if (sep_len && lst->next && (lst->next)->content && \
				*((char *)(lst->next)->content) && (size += sep_len))
					ft_putstr_len(separator, sep_len);
			}
			lst = lst->next;
		}
		return (size);
	}
	return (ft_lst_putstr_sep_free_put2(str, str_size));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:13:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/09 22:34:31 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lst_to_array(t_list *lst)
{
	void	*result;
	void	*temp_arr;
	t_list	*temp_lst;

	if (!lst)
		return (NULL);
	if (!(result = (void *)malloc(ft_lst_all_content_size(lst))))
		return (NULL);
	temp_lst = lst;
	temp_arr = result;
	while (temp_lst)
	{
		ft_memcpy(temp_arr, temp_lst->content, lst->content_size);
		temp_arr = ft_jump(temp_arr, lst->content_size);
		temp_lst = temp_lst->next;
	}
	return (result);
}

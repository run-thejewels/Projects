/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array_nullterm_free.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 22:11:56 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/09 22:33:35 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_lst_to_array_nullterm_free(t_list *lst)
{
	size_t	len;
	void	*result;
	void	*temp_arr;
	t_list	*temp_lst;

	if (!lst)
		return (NULL);
	len = ft_lst_chain_len(lst);
	if (!(result = (void *)malloc((len + 1) * lst->content_size)))
		return (NULL);
	temp_lst = lst;
	temp_arr = result;
	while (temp_lst)
	{
		ft_memcpy(temp_arr, temp_lst->content, lst->content_size);
		temp_arr = ft_jump(temp_arr, lst->content_size);
		temp_lst = temp_lst->next;
	}
	len *= lst->content_size;
	ft_bzero(ft_jump(result, len), lst->content_size);
	ft_lst_free_chain(lst);
	return (result);
}

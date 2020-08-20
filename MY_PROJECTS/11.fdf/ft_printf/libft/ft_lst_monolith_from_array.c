/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_from_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 22:35:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/08 23:04:58 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_monolith_from_array(void *arr, size_t size, size_t amount)
{
	t_list	*result;
	t_list	*temp_lst;
	t_list	*temp_arr;

	result = NULL;
	if (!(temp_arr = (t_list *)malloc(amount * size)))
		return (NULL);
	while (amount)
	{
		temp_lst = ft_lst_monolith_lstnew(arr, temp_arr, size);
		ft_lstadd_to_end(&result, temp_lst);
		arr = ft_jump(arr, size);
		temp_lst = ft_jump(temp_lst, sizeof(t_list));
		amount--;
	}
	return (result);
}

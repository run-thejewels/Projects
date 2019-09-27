/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort_quick.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 21:56:45 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/09 22:32:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_sort_quick(t_list *lst, int (*f)(void *, void *))
{
	void	*temp;
	size_t	size;
	size_t	len;
	t_list	*result;

	if (!lst || !f)
		return (NULL);
	size = lst->content_size;
	len = ft_lst_chain_len(lst);
	temp = ft_lst_to_array_free(lst);
	ft_sort_quick(temp, size, len, f);
	result = ft_lst_monolith_from_array(temp, size, len);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_convert_to_monolith.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 17:06:00 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/10 18:41:42 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_monolith_convert_to_monolith(t_list *lst)
{
	size_t	len;
	size_t	size;
	void	*temp;
	t_list	*result;

	if (!lst)
		return (NULL);
	len = ft_lst_chain_len(lst);
	size = lst->content_size;
	temp = ft_lst_to_array_free(lst);
	result = ft_lst_monolith_from_array(temp, size, len);
	return (result);
}

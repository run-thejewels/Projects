/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_counter_out_cs.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:18:28 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/17 19:18:34 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_counter_out_cs(t_list *lst, size_t *counter)
{
	char	*result;
	void	*temp;
	size_t	size;

	*counter = 0;
	if (!lst || !(result = (char *)malloc(ft_lst_all_content_size(lst) + 1)))
		return (NULL);
	temp = (void *)result;
	while (lst)
	{
		size = lst->content_size;
		if (size)
		{
			*counter += size;
			ft_memcpy_safe(temp, lst->content, size);
			temp = ft_jump(temp, size);
		}
		lst = lst->next;
	}
	result[*counter] = '\0';
	return (result);
}

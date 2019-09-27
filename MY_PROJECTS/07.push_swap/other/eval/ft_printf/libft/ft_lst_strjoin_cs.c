/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_cs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:53:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/21 19:53:51 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_cs(t_list *lst)
{
	char	*result;
	void	*temp;
	size_t	size;
	size_t	max;

	if (!lst || !(result = (char *)malloc(ft_lst_all_content_size(lst) + 1)))
		return (NULL);
	temp = (void *)result;
	max = 0;
	while (lst)
	{
		size = lst->content_size;
		if (size)
		{
			max += size;
			ft_memcpy_safe(temp, lst->content, size);
			temp = ft_jump(temp, size);
		}
		lst = lst->next;
	}
	result[max] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lstnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:14:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/20 22:14:55 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_two_list		*ft_binary_lstnew(void const *content, size_t content_size)
{
	t_two_list	*new;

	if (!(new = (t_two_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = malloc(content_size)))
	{
		free(new);
		return (NULL);
	}
	if (!content || !content_size)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ft_memcpy(new->content, content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	new->back = NULL;
	return (new);
}

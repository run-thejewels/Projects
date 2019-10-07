/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:47:33 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/01 19:06:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*dst;

	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		dst->content = NULL;
		dst->content_size = 0;
	}
	else
	{
		if ((dst->content = malloc(content_size)) == NULL)
		{
			free(dst);
			return (NULL);
		}
		ft_memcpy(dst->content, content, content_size);
		dst->content_size = content_size;
	}
	dst->next = NULL;
	return (dst);
}

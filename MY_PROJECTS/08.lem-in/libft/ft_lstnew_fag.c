/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_fag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 18:03:33 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/07/06 12:30:29 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_fag(void *content, size_t content_size)
{
	t_list	*dst;

	if (!(dst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	dst->content = content;
	dst->content_size = content_size;
	dst->next = NULL;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 21:36:48 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 21:40:39 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_strlen(t_list *lst)
{
	size_t	result;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		result += ft_strlen_safe((char *)lst->content);
		lst = lst->next;
	}
	return (result);
}

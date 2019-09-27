/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_all_files_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:50:06 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:50:59 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_get_all_files_free(t_list *paths)
{
	t_list	*result;

	if (!(result = ft_get_all_files(paths)))
		return (NULL);
	ft_lst_free_chain(paths);
	return (result);
}

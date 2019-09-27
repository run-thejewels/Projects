/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this_all_files_is_same_free.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:17:19 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:19:08 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_this_all_files_is_same_free(t_list *files)
{
	int	result;

	result = ft_this_all_files_is_same(files);
	ft_lst_free_chain(files);
	return (result);
}

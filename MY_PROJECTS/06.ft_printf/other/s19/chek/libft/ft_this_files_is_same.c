/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_this_files_is_same.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 19:54:41 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:26:10 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_this_files_is_same(char *file_name_1, char *file_name_2)
{
	void	*f1;
	void	*f2;
	size_t	s1;
	size_t	s2;

	f1 = ft_get_file(file_name_1, &s1);
	f2 = ft_get_file(file_name_2, &s2);
	if (!f1 || !f2 || s1 != s2 || ft_memcmp(f1, f2, s1))
	{
		ft_free_both(f1, f2);
		return (0);
	}
	ft_free_both(f1, f2);
	return (1);
}

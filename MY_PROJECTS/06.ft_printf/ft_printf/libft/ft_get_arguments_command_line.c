/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arguments_command_line.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:46:10 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:47:43 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_get_arguments_command_line(int argc, char **argv)
{
	t_list	*result;
	t_list	*new;
	int		index;

	if (argc <= 1 || !argv)
		return (NULL);
	index = 0;
	argc--;
	result = NULL;
	while (index < argc)
	{
		new = ft_lstnew_no_copy(ft_strdup(argv[index + 1]), \
		ft_strlen(argv[index + 1]) + 1);
		ft_lstadd(&result, new);
		index++;
	}
	result = ft_lst_turn(result);
	return (result);
}

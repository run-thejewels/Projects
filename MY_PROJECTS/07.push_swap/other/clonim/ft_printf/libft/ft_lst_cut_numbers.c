/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_cut_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 19:39:52 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/16 23:38:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_lst_atoi_strings_helper(size_t *indicate, \
	t_list **number, t_list **result)
{
	size_t		size;
	char		*add;

	*indicate = 1;
	if (*number)
	{
		add = ft_lst_strjoin_counter_out_free_cs(ft_lst_turn(*number), &size);
		ft_lstadd(result, \
			ft_lstnew_no_copy(add, size + 1));
		*number = NULL;
	}
}

t_list			*ft_lst_cut_numbers(char *ex)
{
	size_t		i;
	size_t		indicate;
	t_list		*n;
	t_list		*result;

	ft_nuller_double_point((void **)&n, (void **)&result);
	ft_nuller_double_size_t(&i, &indicate);
	while (ex[i])
	{
		if (ft_isdigit(ex[i]))
		{
			indicate = 0;
			ft_lstadd(&n, ft_lstnew_no_copy(ft_strnew_filler(1, ex[i]), 1));
		}
		else
		{
			if (ex[i] == '-' && (indicate || !i) && ft_isdigit(ex[i + 1]))
				ft_lstadd(&n, ft_lstnew_no_copy(ft_strnew_filler(1, ex[i]), 1));
			else
				ft_lst_atoi_strings_helper(&indicate, &n, &result);
		}
		i++;
	}
	ft_lst_atoi_strings_helper(&indicate, &n, &result);
	return (ft_lst_turn(result));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_add.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 18:45:23 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/29 20:03:12 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_lasatemp(char *str, size_t size, char residue)
{
	t_list		*lst;
	char		temp;

	lst = NULL;
	while (size)
	{
		temp = str[size - 1] - '0' + residue;
		if (temp > 9)
		{
			residue = 1;
			temp -= 10;
		}
		else
			residue = 0;
		temp += '0';
		ft_lstadd(&lst, ft_lstnew(&temp, 1));
		size--;
	}
	if (residue)
	{
		residue += '0';
		ft_lstadd(&lst, ft_lstnew(&residue, 1));
	}
	return (ft_lst_strjoin_counter_out_cs(lst, &size));
}

static int		resizes(char **to_fly, size_t *size, char **temp, size_t *s)
{
	if (size[1])
	{
		*s = size[1];
		*temp = to_fly[0];
		return (0);
	}
	else if (size[2])
	{
		*s = size[2];
		*temp = to_fly[1];
		return (0);
	}
	return (1);
}

static char		*ft_long_arithmetic_string_add_result(char **to_fly, \
	size_t *size, t_list *lst, char residue)
{
	char		*temp_res;
	char		*temp;
	size_t		s;

	if (lst)
		temp_res = ft_lst_strjoin_counter_out_cs(lst, &size[0]);
	else
	{
		if (size[1])
			return (ft_strdup(to_fly[0]));
		return (ft_strdup(to_fly[1]));
	}
	if (resizes(to_fly, size, &temp, &s))
	{
		if (!residue)
			return (temp_res);
		return (ft_strjoin_free_2("1", temp_res));
	}
	if (!(temp = ft_strjoin_fr_both(ft_lasatemp(temp, s, residue), temp_res)))
		return (ft_strnew_filler(1, '0'));
	return (temp);
}

static char		*ft_long_arithmetic_string_add_work(char **fly, \
	size_t *size)
{
	t_list		*lst;
	char		temp;
	char		residue;

	lst = NULL;
	residue = 0;
	while (size[0])
	{
		temp = fly[0][size[1] - 1] - '0' + fly[1][size[2] - 1] - '0' + residue;
		if (temp > 9)
		{
			residue = 1;
			temp -= 10;
		}
		else
			residue = 0;
		temp += '0';
		ft_lstadd(&lst, ft_lstnew(&temp, 1));
		size[2]--;
		size[1]--;
		size[0]--;
	}
	return (ft_long_arithmetic_string_add_result(fly, size, lst, residue));
}

char			*ft_math_longar_str_add(char *n1, char *n2)
{
	size_t		size[3];
	char		*to_fly[2];

	if (!n1 || !n2)
		return (NULL);
	if (n1[0] != '-' && n2[0] == '-')
		return (ft_math_longar_str_subtraction(n1, ft_jump(n2, 1)));
	if (n1[0] == '-' && n2[0] != '-')
		return (ft_math_longar_str_subtraction(n2, ft_jump(n1, 1)));
	if (n1[0] == '-' && n2[0] == '-')
		return (ft_strjoin_free_2("-", ft_math_longar_str_add(n1 + 1, n2 + 1)));
	size[1] = ft_strlen(n1);
	size[2] = ft_strlen(n2);
	if (size[1] > size[2])
		size[0] = size[2];
	else
		size[0] = size[1];
	to_fly[0] = n1;
	to_fly[1] = n2;
	return (ft_long_arithmetic_string_add_work(to_fly, size));
}

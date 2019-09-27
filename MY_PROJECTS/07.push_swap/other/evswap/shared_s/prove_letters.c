/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prove_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:21:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 19:21:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static int prove_string(char *str)
{
	size_t index;
	char prev;

	index = 0;
	prev = '\0';
	while (str[index])
	{
		if (str[index] == '-')
		{
			if (!ft_isdigit(str[index + 1]) || (prev && !ft_isspace(prev)))
				return (0);
			index++;
			continue ;
		}
		if (!ft_isdigit(str[index]) && !ft_isspace(str[index]))
			return (0);
		prev = str[index];
		index++;
	}
	return (1);
}

int prove_letters(t_list *lst)
{
	size_t index;

	index = 0;
	while (lst)
	{
		if (lst->content && !(prove_string(lst->content)))
			return (0);
		lst = lst->next;
	}
	return (1);
}

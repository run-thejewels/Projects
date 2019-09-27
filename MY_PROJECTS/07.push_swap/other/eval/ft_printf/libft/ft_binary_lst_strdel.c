/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lst_strdel.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 19:47:43 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/20 20:04:32 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		binary_zero_and_free(char *str)
{
	if (str)
	{
		ft_bzero(str, ft_strlen(str));
		free(str);
	}
}

static void		binary_lincker(t_two_list *two)
{
	t_two_list	*temp;

	if ((two->next)->next)
		((two->next)->next)->back = two;
	two->content = (two->next)->content;
	two->content_size = (two->next)->content_size;
	temp = two->next;
	two->next = (two->next)->next;
	free(temp);
}

void			ft_binary_lst_strdel(t_two_list **alst)
{
	if (!alst)
		return ;
	binary_zero_and_free((char *)(*alst)->content);
	if ((*alst)->next)
		binary_lincker(*alst);
	else
	{
		if ((*alst)->back)
		{
			((*alst)->back)->next = NULL;
			free(*alst);
		}
		else
			free(*alst);
	}
	*alst = NULL;
}

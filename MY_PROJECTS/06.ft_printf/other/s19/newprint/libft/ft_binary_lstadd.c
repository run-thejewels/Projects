/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary_lstadd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 22:58:46 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/01/20 22:58:48 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_binary_lstadd(t_two_list **alst, t_two_list *new)
{
	t_two_list *temp;

	if (alst && new)
	{
		temp = *alst;
		while (temp->back)
			temp = temp->back;
		new->next = temp;
		*alst = new;
	}
}

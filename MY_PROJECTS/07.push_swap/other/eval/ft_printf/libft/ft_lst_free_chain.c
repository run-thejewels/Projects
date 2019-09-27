/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:58:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/02/19 21:59:54 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lst_free_chain(t_list *chain)
{
	t_list	*temp;

	while (chain)
	{
		temp = chain->next;
		free(chain->content);
		free(chain);
		chain = temp;
	}
}

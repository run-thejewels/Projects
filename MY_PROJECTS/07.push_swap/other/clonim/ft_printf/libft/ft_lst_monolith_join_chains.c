/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_monolith_join_chains.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 18:42:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/13 19:00:24 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_monolith_join_chains(t_list *l1, t_list *l2)
{
	if (!l1)
		return (l2);
	if (!l2)
		return (l1);
	return (ft_lst_monolith_convert_to_monolith(ft_lst_join(l1, l2)));
}

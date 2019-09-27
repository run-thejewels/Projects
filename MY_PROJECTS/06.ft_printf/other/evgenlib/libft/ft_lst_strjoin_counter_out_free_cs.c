/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_counter_out_free_cs.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 19:25:15 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/17 19:25:16 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_counter_out_free_cs(t_list *lst, size_t *counter)
{
	char	*result;

	if (!lst || !counter)
		return (NULL);
	result = ft_lst_strjoin_counter_out_cs(lst, counter);
	ft_lst_free_chain(lst);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_counter_out_free.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:29:02 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/14 16:33:25 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_counter_out_free(t_list *lst, size_t *counter)
{
	char	*result;

	if (!lst || !counter)
		return (NULL);
	result = ft_lst_strjoin_counter_out(lst, counter);
	ft_lst_free_chain(lst);
	return (result);
}

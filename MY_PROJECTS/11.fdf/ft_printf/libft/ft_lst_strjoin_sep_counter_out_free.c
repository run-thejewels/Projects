/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_sep_counter_out_free.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:37:33 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:37:57 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_sep_counter_out_free(t_list *lst, \
	char *separator, size_t *counter)
{
	char	*result;

	if (!lst || !counter)
		return (NULL);
	result = ft_lst_strjoin_sep_counter_out(lst, separator, counter);
	ft_lst_free_chain(lst);
	return (result);
}

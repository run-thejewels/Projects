/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_fr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 23:24:55 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/05 00:01:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_fr(t_list *lst)
{
	char	*result;

	result = ft_lst_strjoin(lst);
	ft_lst_free_chain(lst);
	return (result);
}

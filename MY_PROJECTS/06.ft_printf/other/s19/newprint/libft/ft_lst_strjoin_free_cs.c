/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_free_cs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:52:13 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/21 19:52:15 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_free_cs(t_list *lst)
{
	char	*result;

	result = ft_lst_strjoin_cs(lst);
	ft_lst_free_chain(lst);
	return (result);
}

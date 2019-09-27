/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_strjoin_sep_free.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 19:30:09 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/19 19:30:44 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_lst_strjoin_sep_free(t_list *lst, char *separator)
{
	char	*result;

	result = ft_lst_strjoin_sep(lst, separator);
	ft_lst_free_chain(lst);
	return (result);
}

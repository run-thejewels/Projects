/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:32:39 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 16:38:56 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_lst_stack_size(size_t channel)
{
	size_t	size;

	size = ft_lst_chain_len((ft_lst_stack_new_stack(channel))->content);
	return (size);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:40:04 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/20 13:01:24 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void	*a;

	if (!(a = (void*)malloc(sizeof(void) * (size + 1))))
		return (NULL);
	return (ft_memset(a, '\0', size + 1));
}

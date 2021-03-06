/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:48:40 by kbethany          #+#    #+#             */
/*   Updated: 2018/12/10 19:23:06 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "libft.h"

void	ft_putstr(char const *str)
{
	size_t i;

	i = 0;
	if (str != NULL)
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
}

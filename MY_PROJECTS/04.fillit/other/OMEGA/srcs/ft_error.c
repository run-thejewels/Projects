/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:29:21 by jmaynard          #+#    #+#             */
/*   Updated: 2019/01/26 17:36:51 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_error(int er)
{
	if (er == 1)
		write(1, "open() error\n", 13);
	else if (er == 2)
		write(1, "close() error\n", 14);
	else if (er == 3)
		write(1, "error\n", 6);
	else if (er == 4)
		write(1, "malloc() error\n", 15);
	exit(EXIT_FAILURE);
}

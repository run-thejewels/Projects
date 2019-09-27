/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:46:14 by kfalia-f          #+#    #+#             */
/*   Updated: 2019/02/02 21:10:09 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_output(char **result)
{
	int i;

	i = 0;
	while (result[i])
	{
		ft_putstr(result[i]);
		ft_putchar('\n');
		i++;
	}
	ft_mass2del(&result);
}

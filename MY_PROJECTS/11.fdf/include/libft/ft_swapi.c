/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Nik <Nik@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:24:50 by vinograd          #+#    #+#             */
/*   Updated: 2019/08/14 11:12:38 by Nik              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swapi(int *c1, int *c2)
{
	int n;

	n = *c1;
	*c1 = *c2;
	*c2 = n;
}

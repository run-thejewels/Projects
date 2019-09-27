/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 19:09:50 by kbethany          #+#    #+#             */
/*   Updated: 2019/02/27 13:22:01 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int type(char a)
{
	if ( a == 'd' || a == 'i')
		return (1);
	else if (a == 'o')
		return (2);
	else if ( a == 'u')
		return (3);
	else if (a == 'x' || a == 'X')
		return (4);
	else if (a == 'f' || a == 'F')
		return (5);
	else if (a == 'c')
		return (6);
	else if (a == 's' || a == 'S')
		return (7);
	else if (a == 'p')
		return (8);
	else if (a == '%')
		return (9);
	return (0);
}

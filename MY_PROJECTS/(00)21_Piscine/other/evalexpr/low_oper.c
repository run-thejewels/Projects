/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_oper.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:35:56 by kbethany          #+#    #+#             */
/*   Updated: 2018/10/07 17:44:36 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	low_oper(char *str)
{
	char	oper;
	int		a1;
	int		a2;

	a1 = ft_atoi(str);
	while (str[0] != '\0' && str[0] != ')')
	{
		oper = str[0];
		str = str + 1;
		if (oper == '+' || oper == '-')
			a2 = high_oper(str);
		else
			a2 = ft_atoi(str);
		a1 = do_op(a1, a2, oper);
	}
	return (a1);
}

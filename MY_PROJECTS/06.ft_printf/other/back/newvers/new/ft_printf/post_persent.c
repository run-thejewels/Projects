/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_persent.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:43:12 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:09:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t post_persent(char *str, va_list *arguments, int *count)
{
	t_flag	flag;
	size_t	type_len;
	size_t	out_len;

	type_len = 0;
	if (!(type_len += check_flags(str, &flag)))
	{
		return (1);
	}
	else
	{
		out_len = out_from_flag(&flag, arguments);
	}
	*count += out_len;
	return (type_len + 1);
}

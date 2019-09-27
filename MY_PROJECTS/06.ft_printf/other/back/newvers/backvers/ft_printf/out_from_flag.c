/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_from_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:38:54 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:05:59 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	out_from_flag(t_flag *flag, va_list *arguments)
{
	if (flag->flag_5 == 'p')
		return (print_flag_p(flag, arguments));
	else if (flag->flag_5 == 'x' || flag->flag_5 == 'X')
		return (print_flag_x(flag, arguments));
	else if (flag->flag_5 == 'o')
		return (print_flag_o(flag, arguments));
	else if (flag->flag_5 == 'u')
		return (print_flag_u(flag, arguments));
	else if (flag->flag_5 == 'd' || flag->flag_5 == 'i')
		return (print_flag_d(flag, arguments));
	else if (flag->flag_5 == 'f')
		return (print_flag_f(flag, arguments));
	else
		return (print_flag_sc(flag, arguments));
	return (0);
}

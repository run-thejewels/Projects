/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flag_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:18:57 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:15:12 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

size_t	print_flag_p(t_flag *flag, va_list *arguments)
{
	void	*p;
	char	*str;
	int		temp;

	p = va_arg(*arguments, void*);
	ft_putstr_len("0x", 2);
	flag->ll = 0;
	flag->l = 0;
	str = ft_itoa_base_long(flag,(unsigned long)p, 16);
	temp = ft_strlen(str);
	str = ft_str_lower(str);
	ft_putstr_len(str, temp);
	free(str);
	return (temp + 2);
}

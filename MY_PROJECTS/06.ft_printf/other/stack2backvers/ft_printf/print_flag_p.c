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
	int		temp;

	p = va_arg(*arguments, void*);
	flag->ll = 0;
	flag->l = 0;
	flag->str = ft_itoa_base_long(flag,(unsigned long)p, 16);
	flag->str = ft_strjoin_free_2("0x", flag->str);
	temp = ft_strlen(flag->str);
	flag->str = ft_str_lower(flag->str);
	ft_lstadd(&(flag->lst), ft_lstnew_without_copy(flag->str, temp));
	return (temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:49:02 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:00:10 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	char *temp;
	int p_indicate;
	va_list	arguments;
	t_list *lst;
	size_t size;

	p_indicate = 0;
	lst = NULL;
	str = (char *)format;
	va_start(arguments, format);
	if (!*str)
		return (0);
	while (*str)
	{
		// ft_putstr("1");
		size = just_to_print_len(str, &p_indicate, lst);
		if (size && p_indicate != -1)
			ft_lstadd(&lst, ft_lstnew_without_copy((temp = ft_strdup_n(str, size)), size));
		// ft_putstr(temp);
		// ft_putstr("\n");
		str += size;
		if (p_indicate)
			str += post_persent(str + 1, &arguments, &lst);
		else
			break ;
	}
	va_end(arguments);
	return (ft_lst_putstr_free(ft_lst_turn(lst)));
}

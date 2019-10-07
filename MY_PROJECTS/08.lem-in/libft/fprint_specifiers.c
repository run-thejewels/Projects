/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprint_parse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:00:42 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/30 19:51:48 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*fprint_int_specifier(va_list argptr)
{
	t_list	*dst;

	dst = ft_lstnew_fag(ft_itoa(va_arg(argptr, int)), (size_t)0);
	return (dst);
}

t_list		*fprint_str_specifier(va_list argptr)
{
	t_list	*dst;
	char	*src;

	src = (char *)va_arg(argptr, char *);
	dst = ft_lstnew_fag(ft_strdup(src), (size_t)0);
	return (dst);
}

t_list		*fprint_char_specifier(va_list argptr)
{
	t_list	*dst;
	char	*str;

	str = ft_strnew(1);
	if (str)
		str[0] = (char)va_arg(argptr, int);
	dst = ft_lstnew_fag(str, (size_t)0);
	return (dst);
}

t_list		*fprint_dash_specifier(void)
{
	t_list	*dst;
	char	*str;

	str = ft_strnew(1);
	if (str)
		str[0] = '%';
	dst = ft_lstnew_fag(str, (size_t)0);
	return (dst);
}

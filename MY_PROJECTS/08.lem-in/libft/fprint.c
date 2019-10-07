/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fastprint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 11:39:53 by bsabre-c          #+#    #+#             */
/*   Updated: 2019/08/30 19:09:44 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_addstr_to_list(const char *restrict format, size_t i, \
		size_t begin)
{
	t_list		*dst;
	char		*str;

	if (i - begin <= 0)
		return (NULL);
	dst = ft_lstnew_fag(NULL, (size_t)0);
	str = (char *)malloc(sizeof(char) * (i - begin + 1));
	dst->content = str;
	str[i - begin] = '\0';
	str = ft_strncpy(str, &(format[begin]), i - begin);
	return (dst);
}

static t_list	*ft_add_specifier_to_lst(const char *restrict format, \
		va_list argptr, t_list **lst, size_t *i)
{
	*lst = *lst;
	if (format[*i + 1] == 'd')
	{
		(*i) += 2;
		return (fprint_int_specifier(argptr));
	}
	else if (format[*i + 1] == 's')
	{
		(*i) += 2;
		return (fprint_str_specifier(argptr));
	}
	else if (format[*i + 1] == '%')
	{
		(*i) += 2;
		return (fprint_dash_specifier());
	}
	else if (format[*i + 1] == 'c')
	{
		(*i) += 2;
		return (fprint_char_specifier(argptr));
	}
	(*i)++;
	return (NULL);
}

static t_list	*fprint_parser(const char *restrict format, va_list argptr)
{
	size_t	i;
	size_t	begin;
	t_list	*head;
	t_list	*lst;

	i = 0;
	begin = 0;
	head = ft_lstnew_fag(NULL, (size_t)0);
	lst = head;
	while (format[i])
	{
		while (format[i] && format[i] != '%')
			i++;
		if ((lst->next = ft_addstr_to_list(format, i, begin)))
			lst = lst->next;
		if (format[i])
		{
			if ((lst->next = ft_add_specifier_to_lst(format, argptr, &lst, &i)))
				lst = lst->next;
		}
		begin = i;
	}
	return (head);
}

void			fprint_fd(int fd, const char *format, ...)
{
	va_list		argptr;
	t_list		*head;
	t_list		*tmp;
	size_t		len;

	va_start(argptr, format);
	head = fprint_parser(format, argptr);
	while (head)
	{
		if (head->content)
		{
			len = ft_strlen(head->content);
			write(fd, head->content, len);
			free(head->content);
		}
		tmp = head;
		head = head->next;
		free(tmp);
	}
	va_end(argptr);
}

void			fprint(const char *format, ...)
{
	va_list		argptr;
	t_list		*head;
	t_list		*tmp;
	size_t		len;

	va_start(argptr, format);
	head = fprint_parser(format, argptr);
	while (head)
	{
		if (head->content)
		{
			len = ft_strlen(head->content);
			write(1, head->content, len);
			free(head->content);
		}
		tmp = head;
		head = head->next;
		free(tmp);
	}
	va_end(argptr);
}

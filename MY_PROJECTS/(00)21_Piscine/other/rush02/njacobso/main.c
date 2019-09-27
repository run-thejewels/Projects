/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:45:39 by njacobso          #+#    #+#             */
/*   Updated: 2018/10/07 12:53:15 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_colle2.h"

#define BUF_SIZE 4096

int		allowed_char(char c)
{
	if (c == 'B' || c == '*' || c == '-' || c == '|' ||
		c == 'A' || c == 'o' || c == '/' || c == '\\' ||
		c == 'C' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int		is_rush(char *str)
{
	while (*str)
	{
		if (!allowed_char(*str))
			return (0);
		str++;
	}
	return (1);
}

void	put_error(void)
{
	ft_putstr("Program died. Horribly.");
}

void	output(char *str)
{
	char *name;

	name = get_rush(str);
	while (*name)
	{
		ft_putchar('[');
		while (*name && *name != ' ')
		{
			ft_putchar(*name);
			name++;
		}
		ft_putstr("] [");
		ft_putnbr(get_width(str));
		ft_putstr("] [");
		ft_putnbr(get_height(str));
		ft_putchar(']');
		if (*name == ' ')
		{
			name++;
			ft_putstr(" || ");
		}
	}
}

int		main(void)
{
	char	str[BUF_SIZE + 1];
	int		len;

	len = read(0, &str, BUF_SIZE + 1);
	if (!len)
	{
		put_error();
		ft_putchar('\n');
		return (0);
	}
	str[len] = '\0';
	if (!is_rush(str))
		put_error();
	else if (*get_rush(str) == ' ')
	{
		put_error();
	}
	else
	{
		output(str);
	}
	ft_putchar('\n');
	return (0);
}

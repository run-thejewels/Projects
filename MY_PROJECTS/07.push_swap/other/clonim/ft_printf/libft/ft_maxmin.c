/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 23:10:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/03 17:05:46 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static short int		short_max(void)
{
	short int			temp;
	size_t				index;

	if (sizeof(short int) == 2)
		return (32767);
	index = sizeof(short int) * 8 - 2;
	temp = 1;
	while (index)
	{
		index -= 1;
		temp *= 2;
	}
	temp -= 1;
	temp *= 2;
	temp += 1;
	return (temp);
}

static char				char_max(void)
{
	char				temp;
	size_t				index;

	if (sizeof(char) == 1)
		return (127);
	index = sizeof(char) * 8 - 2;
	temp = 1;
	while (index)
	{
		index -= 1;
		temp *= 2;
	}
	temp -= 1;
	temp *= 2;
	temp += 1;
	return (temp);
}

static long long int	ft_min(char *type)
{
	if (!ft_strcmp(type, "long") || !ft_strcmp(type, "long int"))
		return (~((long long int)(~((unsigned long int)0) / 2)));
	if (!ft_strcmp(type, "long long") || !ft_strcmp(type, "long long int"))
		return (~((long long int)(~((unsigned long long int)0) / 2)));
	if (!ft_strcmp(type, "int"))
		return (~((long long int)((int)(~((unsigned int)0) / 2))));
	if (!ft_strcmp(type, "short") || !ft_strcmp(type, "short int"))
		return (~(long long int)short_max());
	if (!ft_strcmp(type, "char"))
		return (~(long long int)(char_max()));
	return (0);
}

long long int			ft_maxmin(char *type, char *maxmin)
{
	if (!type || !maxmin)
		return (0);
	if (!ft_strcmp(maxmin, "max"))
	{
		if (!ft_strcmp(type, "long") || !ft_strcmp(type, "long int"))
			return ((long long int)(~((unsigned long int)0) / 2));
		if (!ft_strcmp(type, "long long") || !ft_strcmp(type, "long long int"))
			return ((long long int)(~((unsigned long long int)0) / 2));
		if (!ft_strcmp(type, "int"))
			return ((long long int)((int)(~((unsigned int)0) / 2)));
		if (!ft_strcmp(type, "unsigned int") || !ft_strcmp(type, "unsigned"))
			return ((long long int)(~((unsigned int)0)));
		if (!ft_strcmp(type, "short") || !ft_strcmp(type, "short int"))
			return ((long long int)short_max());
		if (!ft_strcmp(type, "char"))
			return ((long long int)(char_max()));
		if (!ft_strcmp(type, "unsigned char"))
			return ((long long int)char_max() * 2 + 1);
		if (!ft_strcmp(type, "size_t"))
			return ((long long int)(~(size_t)0));
	}
	if (!ft_strcmp(maxmin, "min"))
		return (ft_min(type));
	return (0);
}

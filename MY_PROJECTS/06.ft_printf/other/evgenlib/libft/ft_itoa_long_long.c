/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:31:12 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/05/24 19:44:47 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				numeric(long long int c)
{
	int					result;

	if (!c)
		return (1);
	result = 0;
	if (c < 0)
		result++;
	while (c)
	{
		c /= 10;
		result++;
	}
	return (result);
}

static long long int	ft_itoa_long_long_shorter(t_list **lst, long long int n)
{
	int					size;
	long long int		minus;

	size = numeric(n) - 2;
	minus = n;
	while (1)
	{
		if (!(minus / 10))
			break ;
		minus /= 10;
	}
	minus *= -1;
	*lst = ft_lstnew_no_copy(ft_strnew_filler(1, minus + '0'), 1);
	while (size)
	{
		minus *= 10;
		size -= 1;
	}
	n += minus;
	return (n);
}

char					*ft_itoa_long_long(long long int n)
{
	t_list				*lst;
	t_list				*correct;
	char				*fil;
	long long int		temp;

	if (!n)
		return (ft_strnew_filler(1, '0'));
	lst = NULL;
	correct = NULL;
	temp = n;
	if (n == ft_maxmin("long long", "min"))
		temp = ft_itoa_long_long_shorter(&correct, n);
	if (temp < 0)
		temp = temp * -1;
	while (temp)
	{
		fil = ft_strnew_filler(1, temp % 10 + '0');
		ft_lstadd(&lst, ft_lstnew_no_copy(fil, 1));
		temp /= 10;
	}
	if (correct)
		ft_lstadd(&lst, correct);
	if (n < 0)
		ft_lstadd(&lst, ft_lstnew("-", 2));
	return (ft_lst_strjoin_fr(lst));
}

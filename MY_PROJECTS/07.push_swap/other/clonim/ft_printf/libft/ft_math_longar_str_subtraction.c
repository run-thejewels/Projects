/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_subtraction.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:51:53 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/06/29 19:54:16 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	minder(char *num)
{
	size_t	index;

	index = 0;
	while (num[index])
	{
		if (!(num[index] == '0'))
		{
			num[index] -= 1;
			break ;
		}
		index++;
	}
	while (index > 0)
	{
		num[index - 1] += 9;
		index--;
	}
}

static char	*ft_subtraction_worker(char *s1, char *s2)
{
	size_t	index;
	char	*n1;
	char	*n2;

	index = 0;
	n1 = s1;
	n2 = s2;
	ft_str_reverse(s1);
	ft_str_reverse(s2);
	while (n1[index] && n2[index])
	{
		if (n1[index] >= n2[index])
			n1[index] = n1[index] - n2[index] + '0';
		else
		{
			minder(&n1[index + 1]);
			n1[index] = 10 + n1[index] - n2[index] + '0';
		}
		index++;
	}
	ft_str_reverse(s1);
	ft_str_reverse(s2);
	return (n1);
}

static char	*ft_subtraction_cut(char *n1, char *n2)
{
	char	*result;
	size_t	count;

	if (n2[0] == '0')
		return (ft_strdup(n2));
	if ((count = ft_strlen(n1)) == ft_strlen(n2) && count == 1)
		return (ft_strnew_filler(1, *n1 - *n2 + '0'));
	if (!(result = ft_subtraction_worker(n1, n2)))
		return (NULL);
	count = 0;
	while (result[count] == '0')
		count++;
	if (count == ft_strlen(result))
		return (ft_strnew_filler(1, '0'));
	if (count)
		result = ft_strdup(ft_jump(result, count));
	return (result);
}

static char	*ft_subtraction_gasket(char *n1, char *n2, int ind)
{
	int		prove;
	char	*result;

	if (!n1 || !n2)
		return (ft_free_both(n1, n2));
	if ((prove = ft_math_longar_str_comparison(n1, n2)) == 1 || !prove)
	{
		result = ft_subtraction_cut(n1, n2);
		if (ind)
			ft_free_both(n1, n2);
		return (result);
	}
	else if (prove == -1)
	{
		if (ind)
		{
			result = ft_strjoin_free_2("-", ft_subtraction_cut(n2, n1));
			ft_free_both(n1, n2);
			return (result);
		}
		return (ft_strjoin("-", ft_subtraction_cut(n2, n1)));
	}
	return (NULL);
}

char		*ft_math_longar_str_subtraction(char *n1, char *n2)
{
	char	*result;

	if (!n1 || !n2)
		return (NULL);
	n1 = ft_strdup(n1);
	n2 = ft_strdup(n2);
	if (!n1 || !n2)
		return (ft_free_both(n1, n2));
	if (n1[0] != '-' && n2[0] != '-')
		return (ft_subtraction_gasket(n1, n2, 1));
	if (n1[0] != '-' && n2[0] == '-')
	{
		result = ft_math_longar_str_add(n1, ft_jump(n2, 1));
		ft_free_both(n1, n2);
		return (result);
	}
	if (n1[0] == '-' && n2[0] != '-')
	{
		result = ft_strjoin_free_2("-", ft_math_longar_str_add(n1 + 1, n2));
		ft_free_both(n1, n2);
		return (result);
	}
	result = ft_subtraction_gasket(ft_jump(n2, 1), ft_jump(n1, 1), 0);
	ft_free_both(n1, n2);
	return (result);
}

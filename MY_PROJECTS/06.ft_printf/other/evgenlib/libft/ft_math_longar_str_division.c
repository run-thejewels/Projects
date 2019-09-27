/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_longar_str_division.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 18:30:41 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/09 18:41:33 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_math_longar_str_division_adder(char *n1, char *n2, char *begin)
{
	char	*temp;
	int		cmp;

	temp = ft_math_longar_str_multi(n2, begin);
	if ((cmp = ft_math_longar_str_comparison(temp, n1)) < 0)
	{
		free(temp);
		return (ft_math_longar_str_division_adder(n1, n2, \
			ft_strjoin_free_1(begin, "0")));
	}
	else if (cmp == 0)
	{
		free(temp);
		return (begin);
	}
	free(temp);
	return (ft_strdup_n_free(begin, ft_strlen(begin) - 1));
}

static void	ft_division_norme_crutch(char *str, char *str2)
{
	free(str2);
	(*str)--;
}

static char	*ft_math_longar_str_division_helper(char *n1, char *n2)
{
	t_iter	i;
	size_t	index;

	i.s = ft_math_longar_str_division_adder(n1, n2, ft_strdup("1"));
	index = 0;
	while (i.s[index])
	{
		while (i.s[index] <= '9')
		{
			i.chr = ft_math_longar_str_multi(n2, i.s);
			if (ft_math_longar_str_comparison(i.chr, n1) > 0)
			{
				ft_division_norme_crutch(&(i.s[index]), i.chr);
				break ;
			}
			else if (ft_math_longar_str_comparison(i.chr, n1) == 0)
				return (ft_free_and_return(i.chr, i.s));
			free(i.chr);
			if (i.s[index] == '9')
				break ;
			i.s[index]++;
		}
		index++;
	}
	return (i.s);
}

char		*ft_math_longar_str_division(char *n1, char *n2)
{
	char	*result;

	if (!n1 || !n2 || n2[0] == '0')
		return (NULL);
	if (n1[0] == '-' && n2[0] == '-')
		result = ft_math_longar_str_division(ft_jump(n1, 1), ft_jump(n2, 1));
	else if (n1[0] == '-' && n2[0] != '-')
	{
		result = ft_math_longar_str_division(ft_jump(n1, 1), n2);
		result = ft_strjoin_free_2("-", result);
	}
	else if (n1[0] != '-' && n2[0] == '-')
	{
		result = ft_math_longar_str_division(n1, ft_jump(n2, 1));
		result = ft_strjoin_free_2("-", result);
	}
	else
	{
		if (ft_math_longar_str_comparison(n2, n1) > 0)
			return (ft_strdup("0"));
		result = ft_math_longar_str_division_helper(n1, n2);
	}
	return (result);
}

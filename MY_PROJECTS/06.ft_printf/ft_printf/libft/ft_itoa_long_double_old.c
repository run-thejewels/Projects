/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_double_old.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:43:22 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/06 19:23:03 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int				one_num_from_multi_num_ld(char *num, size_t *ind_in)
{
	size_t				ind_out;

	if (!*(num + 1))
	{
		*ind_in = 0;
		return ((int)(num - '0'));
	}
	if (one_num_from_multi_num_ld(num + 1, &ind_out) + ind_out >= 5)
	{
		if (*num - '0' + ind_out <= 9)
		{
			*ind_in = 0;
			return ((int)(*num - '0' + ind_out));
		}
		else
		{
			*ind_in = 1;
			return ((*num - '0' + ind_out) - 10);
		}
	}
	*ind_in = 0;
	return ((int)*num - '0' + ind_out);
}

static void				ft_round_en(char *u, size_t a, char **o, long double n)
{
	size_t				i;

	u[a - 1] = (char)one_num_from_multi_num_ld(u + a - 1, &i) + i + '0';
	u[a] = '\0';
	if (i)
	{
		while (a)
		{
			if (u[a - 1] - '0' + i > 9)
				u[a - 1] = '0';
			else
			{
				u[a - 1] = u[a - 1] + 1;
				i = 0;
				break ;
			}
			a--;
		}
		if (i)
		{
			free(*o);
			*o = ft_itoa_long_double_old(ft_math_rounding_down_l_double(n) \
			+ 1, a);
		}
	}
}

static void				ft_round_endstr_ld(char *num, \
	size_t acc, char **or, long double n)
{
	size_t				difference;
	char				*temp;

	if (!acc)
	{
		ft_memcmp(num, "0", 2);
	}
	else if (ft_strlen(num) > acc)
	{
		ft_round_en(num, acc, or, n);
	}
	else if (ft_strlen(num) < acc)
	{
		temp = *or;
		difference = acc - ft_strlen(num);
		*or = ft_strjoin_fr_both(*or, ft_new_null_str(difference));
	}
}

static char				*str_from_l_double(char *s, long double *n, size_t size)
{
	size_t				count;
	size_t				index;
	long double			temp;
	char				dot_indicate;

	index = 0;
	dot_indicate = 0;
	count = ft_math_long_double_normilize(n);
	while (index < size)
	{
		temp = ft_math_rounding_down_l_double(*n);
		s[index] = (char)temp + '0';
		*n = (*n - temp) * 10;
		count--;
		if (!count && !dot_indicate)
		{
			index++;
			s[index] = '.';
			dot_indicate++;
		}
		index++;
	}
	s[size] = '\0';
	return (s);
}

char					*ft_itoa_long_double_old(long double num, \
	size_t accuracy)
{
	char				*result;
	char				*temp;
	size_t				size;
	int					minus;

	minus = 0;
	size = ft_math_numlen_long_double(num);
	if (num < 0.0)
	{
		num *= -1;
		minus = 1;
	}
	if (num - ft_math_rounding_down_l_double(num))
		size++;
	if (!(result = (char *)malloc(size + 1)))
		return (NULL);
	result = str_from_l_double(result, &num, size);
	temp = result;
	if (ft_strlen_safe(ft_strchr(result, '.')) > accuracy + 1)
		ft_round_endstr_ld(ft_strchr(result, '.') + 1, accuracy, &temp, num);
	if (!(result = ft_strdup_free(ft_str_disnuller_end(temp))))
		return (NULL);
	if (minus)
		result = ft_strjoin_free_2("-", result);
	return (result);
}

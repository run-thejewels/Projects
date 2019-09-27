/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:35:49 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/03/07 16:33:10 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*z_c_d(char *num_str, double num)
{
	size_t			index;
	double			temp;
	char			str[7];
	char			*str_temp;
	char			*result;

	index = 0;
	temp = 0.1;
	while (num < temp && index != 6)
	{
		temp /= 10.0;
		index++;
	}
	if (!index)
		return (num_str);
	ft_memset(str, '0', index);
	str[index] = '\0';
	if (!(str_temp = ft_strdup(str)))
		return (NULL);
	result = ft_strjoin(str_temp, num_str);
	free(str_temp);
	return (result);
}

static double		post_dot_size_num_d(double residue)
{
	if (residue < 0)
		residue *= -1.0;
	while (residue - ft_math_rounding_down_double(residue))
		residue *= 10;
	return (residue);
}

static int			one_num_from_multi_num_d(char *num)
{
	if (!*(num + 1))
		return ((int)(num - '0'));
	if (one_num_from_multi_num_d(num + 1) >= 5)
	{
		if (*num - '0' + 1 <= 9)
			return ((int)(*num - '0' + 1));
		else
			return (9);
	}
	return ((int)*num - '0');
}

static char			*ft_round_endstr_d(char *num)
{
	char			*result;

	if (ft_strlen(num) > 12)
	{
		num[5] = (char)one_num_from_multi_num_d(num + 5) + '0';
		num[6] = '\0';
		result = ft_strdup(num);
		free(num);
		return (result);
	}
	return (num);
}

char				*ft_itoa_double(double num)
{
	long long int	intermediate;
	char			*result;
	char			*temp;
	double			residue;

	intermediate = ft_math_rounding_down_double(num);
	temp = ft_itoa_long_long(intermediate);
	result = ft_strjoin(temp, ".");
	free(temp);
	residue = num - intermediate;
	if (!residue)
	{
		temp = ft_strjoin(result, "0");
		free(result);
		return (temp);
	}
	intermediate = post_dot_size_num_d(residue);
	temp = ft_round_endstr_d(z_c_d(ft_itoa_long_long(intermediate), residue));
	result = ft_strjoin(result, temp);
	free(temp);
	return (result);
}

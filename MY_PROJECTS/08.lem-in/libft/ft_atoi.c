/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 22:02:34 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/11 19:03:27 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atoi_helper(char const *s, int *sign)
{
	int i;

	i = 0;
	*sign = 1;
	while (s[i] == ' ' || s[i] == '\f' || s[i] == '\n' || s[i] == '\r'
			|| s[i] == '\t' || s[i] == '\v')
		i++;
	if (s[i] == '-')
		*sign = -1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] == '0')
		i++;
	return (i);
}

int			ft_atoi(const char *str)
{
	int				sign;
	long long		num;
	int				i;
	int				size;

	num = 0;
	size = 0;
	i = ft_atoi_helper(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		size++;
		num = num * 10 + (str[i] - '0');
		if ((num < 0 || size > 19) && sign == 1)
			return (-1);
		if ((num < 0 || size > 19) && sign == -1)
			return (0);
		i++;
	}
	return ((int)(num * sign));
}

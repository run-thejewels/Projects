/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:33:07 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/12/11 19:13:19 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_atoll(char const *s)
{
	long long	dst;
	int			sign;

	sign = 1;
	dst = 0;
	while (*s == ' ' || *s == '\t' || *s == '\n')
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '-' || *s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		dst = dst * 10 + (long long)(*s - '0');
		s++;
		if (dst < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return (dst * sign);
}

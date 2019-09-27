/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:41:33 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/28 20:33:38 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int i;

	i = 1;
	if (nb == 0)
		return (i);
	else if (nb < 0 || nb > 12)
		return (0);
	else
	{
		while (nb > 1)
		{
			i = i * nb;
			nb--;
		}
		if (nb == 1)
			return (i);
		else
			return (0);
	}
}

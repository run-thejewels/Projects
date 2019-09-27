/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 16:59:29 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/29 16:20:10 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{

	if (nb > 12 || nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
        return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

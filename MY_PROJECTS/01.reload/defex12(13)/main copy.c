/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:14:03 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/28 12:22:17 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_recursive_factorial(int nb);

int	main()
{
	char b;
	int	a;
	
	a = 5;
	b = 'P';
	if (ft_recursive_factorial(a) == 120)
		write(1, &b, 1);
	a = -5;
	if (ft_recursive_factorial(a) == 0)
		write(1, &b, 1);
	a = 0;
	if (ft_recursive_factorial(a) == 1)
        write(1, &b, 1);
}

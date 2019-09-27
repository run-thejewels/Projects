/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 13:09:28 by kbethany          #+#    #+#             */
/*   Updated: 2019/05/04 15:20:33 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "head.h"

int	main()
{

	//ft_printf("%x", 42);
//	ft_printf("%       ");
	//ft_printf("gfdhbfjd\n");
	// ft_printf("%x", 12);
	// ft_printf("\n12345 %#10Xtttt\n", 12);
	ft_printf("@moulitest: %c", 0);

	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("%lx\n", 4294967296);
	ft_printf("%s\n", NULL);
	//ft_printf("%   %\n");
	return (0);
}

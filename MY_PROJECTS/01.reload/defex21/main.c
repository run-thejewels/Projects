/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:15:26 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/23 17:26:13 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
void	ft_putstr(int *str);
int	*ft_range(int min, int max);

int main()
{
	int	a;
	int	b;

	a = 4;
	b = 9;
	ft_putstr(ft_range(a, b));
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:49:45 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/21 16:13:11 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
void	ft_swap(int *a, int *b);

int main()
{
	int i;
	int j;
	int *a;
	int *b;

	i = 0;
	j = 1;
	a = &i;
	b = &j;
	ft_swap(a, b);
	if (i == 1 && j == 0)
		ft_putchar('+');
	return 0;
}
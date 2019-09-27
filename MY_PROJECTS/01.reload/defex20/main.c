/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:15:26 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/23 16:22:55 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);
void	ft_putstr(char *str);
char	*ft_strdup(char *src);

int main()
{
	char	*a;

	a = "abc";
	ft_putstr(ft_strdup(a));
	return 0;
}

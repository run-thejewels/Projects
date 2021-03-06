/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 19:33:13 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/27 13:40:03 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int (*f)(char*))
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (tab[i][j])
	{
		while (tab[i][j] != 0)
		{
			if (f(tab[i]) == 1)
				c++;
			j++;
		}
		j = 0;
		i++;
	}
	return (c);
}

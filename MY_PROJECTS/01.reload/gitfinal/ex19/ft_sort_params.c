/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:27:21 by kbethany          #+#    #+#             */
/*   Updated: 2018/11/29 12:34:45 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0' && s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print(int a, char **b)
{
	char	n;
	int		i;

	i = 1;
	n = '\n';
	while (i < a)
	{
		ft_putstr(b[i]);
		ft_putchar(n);
		i++;
	}
}

int		main(int ac, char **av)
{
	char	*c;
	int		find;
	int		i;

	find = 1;
	while (find)
	{
		find = 0;
		i = 0;
		while (++i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				c = av[i];
				av[i] = av[i + 1];
				av[i + 1] = c;
				find = 1;
			}
		}
	}
	ft_print(ac, av);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njacobso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:38:47 by njacobso          #+#    #+#             */
/*   Updated: 2018/10/07 12:57:34 by njacobso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_width(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int		get_height(char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			c++;
		i++;
	}
	return (c);
}

char	*loop(int i, char *str, int flag)
{
	while (str[i])
	{
		i++;
		if (str[i] == '\n' && flag == 0)
		{
			if (str[i - 1] == 'A' && i > 1)
				return ("rush-02");
			else if (str[i - 1] == 'C' && str[i + 1] == '\0')
				return ("rush-03 rush-04");
			flag++;
		}
		else if (str[i] == '\n' && flag > 0)
		{
			if (str[i - 1] == 'A' && str[i - 2] == '\n')
				return ("rush-03");
			if (str[i - 1] == 'A')
				return ("rush-04");
			if (str[i - 1] == 'C' && str[i - 2] == '\n')
				return ("rush-02 rush-04");
			if (str[i - 1] == 'C')
				return ("rush-03");
		}
	}
	return (0);
}

char	*get_rush(char *str)
{
	int		i;
	char	*a;
	int		flag;

	i = 0;
	a = " ";
	flag = 0;
	if (str[i] == 'o')
		a = "rush-00";
	else if (str[i] == '/')
		a = "rush-01";
	else if (str[i] == 'A' && str[i + 2] == '\0')
		a = "rush-02 rush-03 rush-04";
	if (loop(i, str, flag))
		a = loop(i, str, flag);
	return (a);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:22:37 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 19:23:21 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoinre(char *s1, const char *s2)
{
	char	*s;

	if ((s = ft_strjoin(s1, s2)) == NULL)
		return (NULL);
	free(s1);
	return (s);
}

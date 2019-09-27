/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupre.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfalia-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:01:49 by kfalia-f          #+#    #+#             */
/*   Updated: 2018/12/14 15:43:14 by kfalia-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdupre(const char *s)
{
	char	*s1;

	s1 = ft_strdup(s);
	free((char *)s);
	return (s1);
}
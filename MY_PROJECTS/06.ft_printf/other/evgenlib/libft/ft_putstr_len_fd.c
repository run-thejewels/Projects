/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:47:55 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/04/26 16:49:56 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_putstr_len_fd(char const *s, size_t len, int fd)
{
	if (!s || !len || fd <= 0)
		return (NULL);
	write(fd, s, len);
	return ((char *)s + len);
}

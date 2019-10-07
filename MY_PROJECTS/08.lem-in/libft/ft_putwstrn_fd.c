/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstrn_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: forange- <forange-@student.fr.42>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 14:28:53 by forange-          #+#    #+#             */
/*   Updated: 2019/08/04 14:29:14 by forange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putwstrn_fd(wchar_t *str, size_t len, int fd)
{
	size_t	bytes;

	bytes = 0;
	if (!str || !len)
		return (0);
	while (*str && len)
	{
		bytes += ft_putwchar_fd(*str++, fd);
		len--;
	}
	return (bytes);
}

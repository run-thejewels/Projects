/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsabre-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 17:24:30 by bsabre-c          #+#    #+#             */
/*   Updated: 2018/11/30 20:19:12 by bsabre-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		beg;
	int		end;
	char	*dst;

	if (!s)
		return (NULL);
	beg = 0;
	while (s[beg] == ' ' || s[beg] == '\t' || s[beg] == '\n')
		beg++;
	end = ft_strlen(s) - 1;
	while ((s[end] == ' ' || s[end] == '\t' || s[end] == '\n') && end > beg)
		end--;
	if (beg == end)
		dst = ft_strsub(s, 0, 0);
	dst = ft_strsub(s, beg, end - beg + 1);
	return (dst);
}

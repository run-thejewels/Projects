/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfilnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 16:07:38 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:01:59 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

char	*ft_strfilnew(size_t size, char a)
{
	char	*res;
    
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res = ft_memset(res, a, size);
    res[size] = '\0';
	return (res);
}

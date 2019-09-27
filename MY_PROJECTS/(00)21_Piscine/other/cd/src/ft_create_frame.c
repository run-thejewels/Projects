/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_frame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajon-hol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:05:57 by ajon-hol          #+#    #+#             */
/*   Updated: 2018/10/08 13:09:39 by ajon-hol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_frame	*ft_create_frame(int x_data, int y_data, int size_data)
{
	t_frame *frame;

	frame = (t_frame *)(malloc(sizeof(t_frame)));
	frame->x = x_data;
	frame->y = y_data;
	frame->size = size_data;
	return (frame);
}

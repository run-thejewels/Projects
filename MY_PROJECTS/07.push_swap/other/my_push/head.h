/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 17:11:25 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/17 17:11:27 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define IS_INT(V) V >= INT_MIN && V <= INT_MAX
# define DP 20

typedef struct		s_list
{
  int				      v;
 	struct s_node	  *next;
}       					t_list;

typedef struct		s_stack
{
	int		  		len;
	t_node			*head;
	t_node			*tail;
}       					t_stack;

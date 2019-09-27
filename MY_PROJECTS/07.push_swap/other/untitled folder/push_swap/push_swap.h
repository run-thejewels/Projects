/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:04:23 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/22 17:24:36 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "ft_printf/include/head.h"

typedef struct      s_com
{
  char              *ct;
  struct s_com      *n;
  struct s_com      *b;
}                   t_com;

typedef struct      s_stack
{
    int             va[1000];
    int             vb[1000];
    int             ia;
    int             ib;
    int             max;
    int             min;
    int             in;
    char            com_a;
    int             int_a;
    char            com_b;
    int             int_b;
    int             cline_len;
    int             v;
    t_com           *cs;
    t_com           *ce;

}                   t_stack;

int			  ft_error(void);
int			  ft_isint(char *av);
int				ft_check(char *av, t_stack* l);
void      maxmin(t_stack *l);
t_stack		*ft_parsing(int ac, char **av);
t_stack		*lstnew(void);
int			  ft_isdigit(int c);
int			  ft_strisdigit(char *s);

void 			display(t_stack *l);
void 			display_com(t_stack *list, char* a);

void      alg(t_stack* l);
int       ideal(t_stack* l);
void      sort_tribus(t_stack* l);

void      sort_b(t_stack* l);
int       varios(int b, t_stack* l);
int       sort_a(int b, t_stack* l);
void      sorter(t_stack *l);

t_com     *comnew(t_stack *l, char* s);

int 			ss(t_stack *l, char x);
int       sa(t_stack *l);
int       sb(t_stack *l);
int 			pa(t_stack *l);
int 			pb(t_stack *l);
void 			rs(t_stack *l, char x);
void 			ra(t_stack *l);
void 			rb(t_stack *l);
void 			rrs(t_stack *l, char x);
void 			rra(t_stack *l);
void 			rrb(t_stack *l);

#endif

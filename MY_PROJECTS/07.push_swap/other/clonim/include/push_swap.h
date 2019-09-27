/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:04:23 by kbethany          #+#    #+#             */
/*   Updated: 2019/09/04 13:13:23 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "../ft_printf/include/head.h"

typedef struct		s_com
{
	char			*ct;
	struct s_com	*n;
	struct s_com	*b;
}					t_com;

typedef	struct		s_stack
{
	int				va[1000];
	int				vv[1000];
	int				vb[1000];
	int				ia;
	int				iv;
	int				ib;
	int				max;
	int				min;
	int				in;
	char			com_a[1000];
	int				int_a;
	char			com_b[1000];
	int				int_b;
	int				cline_len;
	int				v;
	t_com			*cs;
	t_com			*ce;

}					t_stack;

void				leaker(t_com *c, t_stack *l);
int					ft_error(t_stack *l);

int					check(char *av, t_stack *l);
int					bonus(char *a, t_stack *l);
t_stack				*parsing(int ac, char **av);

void				comander(t_stack *l, char *str);
void				display(t_stack *l);
t_stack				*lstnew(void);

int					ft_strisdigit(char *s);

void				sort_tribus(t_stack *l);
int					ideal(t_stack *l);
void				reset(t_stack *l);
void				alg(t_stack *l);
void				display_com(t_stack *l, char *a);

void				shreder(t_stack *l);
void				shreder_plusultra(t_stack *l);

void				sort_b(t_stack *l);

int					simetra(t_stack *l);
int					simetrb(t_stack *l);
void				sim_a_bigger(t_stack *l);
void				sim_b_bigger(t_stack *l);

void				sorter(t_stack *l, char a, char b);

t_com				*comnew(t_stack *l, char *s);
void				rrs(t_stack *l, char x);
void				rrv(t_stack *l);
void				rra(t_stack *l);
void				rrb(t_stack *l);

int					ss(t_stack *l, char x);
int					sa(t_stack *l);
int					sv(t_stack *l);
int					sb(t_stack *l);

int					pa(t_stack *l);
int					pb(t_stack *l);
int					pv(t_stack *l);
int					pvb(t_stack *l);

void				rr(t_stack *l, char x);
void				ra(t_stack *l);
void				rv(t_stack *l);
void				rb(t_stack *l);

#endif

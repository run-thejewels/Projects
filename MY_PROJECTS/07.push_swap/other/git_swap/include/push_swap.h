/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 16:11:14 by ademenet          #+#    #+#             */
/*   Updated: 2016/05/30 11:44:21 by ademenet         ###   ########.fr       */
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

/*
** This is my structure list:
*/

typedef struct		s_node
{
	int				v;
	struct s_node	*next;
}					t_node;

/*
** This help me to keep pointers and easily do operations:
*/

typedef struct		s_pslist
{
	int				len;
	t_node			*head;
	t_node			*tail;
}					t_plst;

/*
** push_swap.c
*/

t_plst				*ft_choose(t_plst *la, t_plst *lb, t_plst *sol);

/*
** Lib
*/

t_plst				*ft_pslstnew(void);
t_plst				*ft_lstappend(t_plst *list, int v);
void				ft_lstdellastone(t_plst *l);
void				ft_lstdelallnodes(t_plst *l);
void				ft_lstclear(t_plst *l);
int					ft_isdigit(int c);
int					ft_strisdigit(char *s);
long				ft_atoi(const char *str);
int					ft_isascending(int a, int b);
int					ft_isdescending(int a, int b);
int					ft_issortasc(t_plst *l);
int					ft_issortdes(t_plst *l);
int					ft_error(void);
long				ft_power(int nb, int exp);
int					ft_strcmp(const char *s1, const char *s2);

/*
** ft_parsing.c
*/

t_plst				*ft_parsing(int ac, char **av, int *bonus);
int					ft_checkbonus(char **av, int *bonus);
int					ft_check(t_plst *list, char *av);
int					ft_isint(t_plst *list, char *av);
int					ft_isunique(t_plst *list, int v);

/*
** ft_operations.c
*/

t_plst				*ft_swap(t_plst *l, t_plst *mv, int ab);
t_plst				*ft_push_a(t_plst *la, t_plst *lb, t_plst *mv);
t_plst				*ft_push_b(t_plst *la, t_plst *lb, t_plst *mv);
t_plst				*ft_rotate(t_plst *l, t_plst *mv, int ab);
t_plst				*ft_revrotate(t_plst *l, t_plst *mv, int ab);

/*
** ft_dynamicalgorithm.c
*/

t_plst				*ft_dyn_clean(t_plst *l, t_plst *mv);
t_plst				*ft_dyn_selectmove(t_plst *l, t_plst *mv, int swt);
t_plst				*ft_dyn_copy(t_plst *mv, t_plst *sol);
int					ft_dyn_explore(t_plst *l, t_plst *mv, t_plst *sol,
					int index);
t_plst				*ft_dyn_resolve(t_plst *l);

/*
** ft_sortcocktail.c
*/

t_plst				*ft_sortcocktail_a(t_plst *l, t_plst *mv);

/*
** ft_sortmin.c
*/

int					ft_findmin(t_plst *l);
t_plst				*ft_sortmin(t_plst *la, t_plst *lb, t_plst *mv);

/*
** ft_optimization.c
*/

int					ft_locateit(t_plst *l, int min);
t_plst				*ft_isreverse(t_plst *l, t_plst *mv);

/*
** ft_display.c
*/

void				ft_display(t_plst *mv, int bonus);
void				ft_display_color(t_plst *mv);

/*
** Guests and bonus
*/

int					ft_printf(const char *format, ...);
void				ft_print_l(t_plst *l, char *str);

#endif

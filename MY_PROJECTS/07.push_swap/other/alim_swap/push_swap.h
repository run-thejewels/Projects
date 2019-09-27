/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 13:06:27 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/28 15:11:33 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>
# define N "\x1b[0m"
# define R "\x1b[31m"
# define G "\x1b[32m"
# define Y "\x1b[33m"
# define B "\x1b[34m"
# define M "\x1b[35m"
# define C "\x1b[36m"
# define W "\x1b[37m"
# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct						s_doubly_list
{
	int								value;
	struct s_doubly_list			*prev;
	struct s_doubly_list			*next;
	unsigned int					color:1;
}									t_doubly_list;

typedef struct						s_doubly_command_list
{
	char							*command;
	struct s_doubly_command_list	*prev;
	struct s_doubly_command_list	*next;
}									t_command_list;

typedef struct						s_stack
{
	size_t							len_a;
	t_doubly_list					*top_a;
	t_doubly_list					*btm_a;
	t_doubly_list					*top_b;
	t_doubly_list					*btm_b;
	size_t							size;
	size_t							len_less_pvt;
	size_t							len_more_pvt;
	t_doubly_list					*len_pvts_b;
	t_command_list					*command_list;
	unsigned int					print:1;
	unsigned int					color:1;
}									t_stack;

int									ft_printf(const char *format, ...);
void								sa(t_stack *stack);
void								sb(t_stack *stack);
void								ss(t_stack *stack);
void								pb(t_stack *stack);
void								pa(t_stack *stack);
void								ra(t_stack *stack);
void								rb(t_stack *stack);
void								rr(t_stack *stack);
void								rra(t_stack *stack);
void								rrb(t_stack *stack);
void								rrr(t_stack *stack);
void								print(t_stack *stack);
void								print_commands(t_stack *stack);
void								free_doubly_list(t_doubly_list
		*doubly_list);
void								free_command_list(t_command_list
		*command_list);
char								is_sort_stack(t_doubly_list *top);
void								quicksort(int *arr, int low, int high,
		char asc);
char								is_swap_command(t_stack *stack, char *line);
char								is_push_command(t_stack *stack, char *line);
char								is_rotate_command(t_stack *stack,
		char *line);
char								is_rev_rotate_command(t_stack *stack,
		char *line);
char								is_placing_argv_stack(t_stack *stack,
		int argc, char **argv);
t_doubly_list						*ft_list_new(int value);
t_doubly_list						*del_list_forw(t_stack *stack);
t_doubly_list						*ft_list_push_back(t_stack *stack,
		int value);
t_doubly_list						*ft_list_push_forw(t_stack *stack);
t_command_list						*comm_list(t_stack *stack,
		char *command);
int									find_pvt_stack_a(t_stack *stack, int len);
int									find_pvt_stack_b(t_stack *stack, int len);
char								is_less_pvt_stack_a(t_stack *stack, int len,
		int pvt);
char								is_more_pvt_stack_b(t_stack *stack, int len,
		int pvt);
void								optimizing_commands_list(t_stack *stack);
int									iter_count(t_stack *stack);
void								sort_triple_a(t_stack *stack);
void								initialize(t_stack *stack);
# define SA(stack) sa(stack); stack->command_list = comm_list(stack, "sa\n")
# define SB(stack) sb(stack); stack->command_list = comm_list(stack, "sb\n")
# define SS(stack) ss(stack); stack->command_list = comm_list(stack, "ss\n")
# define RA(stack) ra(stack); stack->command_list = comm_list(stack, "ra\n")
# define RRA(stack) rra(stack); stack->command_list = comm_list(stack, "rra\n")
# define RB(stack) rb(stack); stack->command_list = comm_list(stack, "rb\n")
# define RRB(stack) rrb(stack); stack->command_list = comm_list(stack, "rrb\n")
# define RRR(stack) rrr(stack); stack->command_list = comm_list(stack, "rrr\n")
# define PA(stack) pa(stack); stack->command_list = comm_list(stack, "pa\n")
# define PB(stack) pb(stack); stack->command_list = comm_list(stack, "pb\n")
# define DEF_STATE_A(stack, counter) while (counter) {RRA(stack); counter--;}
# define DEF_STATE_B(stack, counter) while (counter) {RRB(stack); counter--;}
#endif

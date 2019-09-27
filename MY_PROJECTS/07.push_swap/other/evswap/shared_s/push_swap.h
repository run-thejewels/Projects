#ifndef HEAD_H
# define HEAD_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct			s_tacks
{
	int *stack_a;
	size_t size_a;
	int *stack_b;
	size_t size_b;
	int max;
	int min;
	t_list *commands;
}						t_stacks;

typedef struct			s_flaggs
{
	int print;
}						t_flaggs;

int prove_arguments(t_list **lst);
int prove_letters(t_list *lst);
void error_lst_ps(t_list *lst);
void error_input_ps(void);
void unfolding_arguments(t_list *lst);
int structure_filler_ps(t_list *arguments, t_stacks *stacks);
t_list *flags_filler(t_list *arguments, t_flaggs *flags);
void out(t_stacks *stacks);
void sa_ps(t_stacks *stacks, t_flaggs *flags);
void sb_ps(t_stacks *stacks, t_flaggs *flags);
void ss_ps(t_stacks *stacks, t_flaggs *flags);
void pa_ps(t_stacks *stacks, t_flaggs *flags);
void pb_ps(t_stacks *stacks, t_flaggs *flags);
void ra_ps(t_stacks *stacks, t_flaggs *flags);
void rb_ps(t_stacks *stacks, t_flaggs *flags);
void rr_ps(t_stacks *stacks, t_flaggs *flags);
void rra_ps(t_stacks *stacks, t_flaggs *flags);
void rrb_ps(t_stacks *stacks, t_flaggs *flags);
void rrr_ps(t_stacks *stacks, t_flaggs *flags);
void sorting_three(int *ints, size_t size, t_stacks *stacks, t_flaggs *flags);
void search_max_min(t_stacks *stacks);
void algorithm_ps(t_stacks *stacks, t_flaggs *flags);
void to_a(t_stacks *stacks, t_flaggs *flags);
void to_b(t_stacks *stacks, t_flaggs *flags);
int is_sorted_ps(int *ints, size_t size);
int is_sorted_shift_ps(int *ints, size_t size);
size_t is_sorted_shift_in_mind_ps(int *ints, size_t size, int new);
size_t get_index(int *ints, size_t size, int num);
void final_turn(t_stacks *stacks, t_flaggs *flags);
int do_up(size_t index, size_t size);
int fastest_cowboy(t_stacks *stacks);
size_t how_many_steps_to_get_out(size_t index, size_t size);
void print_operations(t_stacks *stacks, char *operation, t_flaggs *flags);
void print_begin(t_stacks *stacks, t_flaggs *flags);
void print_final(t_stacks *stacks);

int prove_operators(t_list *operators);
void error_lst(t_list *lst);
void error_input(void);
void error_operators(t_list *lst, t_stacks *stacks);
void unfolding_arguments(t_list *lst);
int structure_filler(t_list *arguments, t_stacks *stacks);
void sa(t_stacks *stacks);
void sb(t_stacks *stacks);
void ss(t_stacks *stacks);
void pa(t_stacks *stacks);
void pb(t_stacks *stacks);
void ra(t_stacks *stacks);
void rb(t_stacks *stacks);
void rr(t_stacks *stacks);
void rra(t_stacks *stacks);
void rrb(t_stacks *stacks);
void rrr(t_stacks *stacks);
void algorithm(t_stacks *stacks, t_list *operators);
int is_sorted(int *ints, size_t size);
t_list *get_operators(void);

#endif

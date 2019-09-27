#include "../shared_s/push_swap.h"

static int check_operator(char *oper)
{
	if (!oper)
		return (0);
	if (!ft_strstr(oper, "pa") || !ft_strstr(oper, "pb"))
		return (1);
	if (!ft_strstr(oper, "ra") || !ft_strstr(oper, "rb") || \
	!ft_strstr(oper, "rr"))
		return (1);
	if (!ft_strstr(oper, "rra") || !ft_strstr(oper, "rrb") || \
	!ft_strstr(oper, "rrr"))
		return (1);
	if (!ft_strstr(oper, "sa") || !ft_strstr(oper, "sb") || \
	!ft_strstr(oper, "ss"))
		return (1);
	return (0);
}

int prove_operators(t_list *operators)
{
	if (!operators)
		return (1);
	while (operators)
	{
		if (!check_operator(operators->content))
			return (0);
		operators = operators->next;
	}
	return (1);
}

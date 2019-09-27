#include "../shared_s/push_swap.h"

void final_turn(t_stacks *stacks, t_flaggs *flags)
{
	size_t index;

	if (is_sorted_ps(stacks->stack_a, stacks->size_a))
		return ;
	index = 0;
	while (index < stacks->size_a)
	{
		if (index)
		{
			if ((stacks->stack_a)[index - 1] > (stacks->stack_a)[index])
			{
				index--;
				break ;
			}
		}
		index++;
	}
	if ((stacks->size_a - 1) - index > index)
		index = 0;
	while (!(is_sorted_ps(stacks->stack_a, stacks->size_a)))
	{
		if (index)
			ra_ps(stacks, flags);
		else
			rra_ps(stacks, flags);
	}
}

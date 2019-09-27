#include "../shared_s/push_swap.h"

t_list *flags_filler(t_list *arguments, t_flaggs *flags)
{
	t_list *result;

	flags->print = 0;
	if (!arguments)
		return (NULL);
	if (arguments->content)
	{
		if (!ft_strcmp(arguments->content, "-v"))
		{
			flags->print = 1;
			result = arguments->next;
			ft_free_both(arguments->content, arguments);
			return (result);
		}
	}
	return (arguments);
}

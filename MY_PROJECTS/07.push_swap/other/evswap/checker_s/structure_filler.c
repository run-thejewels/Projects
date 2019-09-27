/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahalmon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:20:37 by ahalmon-          #+#    #+#             */
/*   Updated: 2019/07/21 19:46:17 by ahalmon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shared_s/push_swap.h"

static void		structure_nuller(t_stacks *stacks)
{
	stacks->size_b = 0;
	stacks->size_a = 0;
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
}

static int		*convert_to_array(t_list *lst, size_t *size)
{
	int			*result;
	t_list		*temp;
	size_t		index;

	temp = lst;
	index = 0;
	*size = ft_lst_chain_len(lst);
	if (!(result = (int *)malloc(*size * (sizeof(int)))))
		return (NULL);
	while (lst)
	{
		ft_memcpy(&(result[index]), lst->content, sizeof(int));
		index++;
		lst = lst->next;
	}
	ft_lst_free_chain(temp);
	return (result);
}

static void		convert_to_ints(t_list *arguments)
{
	int			temp;

	while (arguments)
	{
		temp = ft_atoi(arguments->content);
		free(arguments->content);
		arguments->content = ft_memdup(&temp, sizeof(int));
		arguments->content_size = sizeof(int);
		arguments = arguments->next;
	}
}

int				structure_filler(t_list *arguments, t_stacks *stacks)
{
	int			*a;
	size_t		size;

	structure_nuller(stacks);
	convert_to_ints(arguments);
	if (!(a = convert_to_array(arguments, &size)))
		return (0);
	stacks->stack_a = a;
	if (!(stacks->stack_b = (int *)malloc(size * sizeof(int))))
	{
		free(a);
		return (0);
	}
	stacks->size_a = size;
	stacks->size_b = 0;
	return (1);
}

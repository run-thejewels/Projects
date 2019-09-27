#include "../shared_s/push_swap.h"

static void *reading(size_t *size)
{
	int		re;
	char	buf[BUFF_SIZE];
	t_list	*lst;

	*size = 0;
	if (BUFF_SIZE < 1 || read(0, buf, 0) < 0)
		return (NULL);
	lst = NULL;
	while ((re = read(0, buf, BUFF_SIZE)) > 0)
	{
		*size += (size_t)re;
		ft_lstadd(&lst, ft_lstnew((void *)buf, (size_t)re));
	}
	return (ft_lst_to_array_free(ft_lst_turn(lst)));
}

static t_list *to_lst(void *file)
{
	char **temp;
	size_t index;
	t_list *lst;

	if (!(temp = ft_strsplit((char *)file, '\n')))
		return (NULL);
	index = 0;
	lst = NULL;
	while (temp[index])
	{
		ft_lstadd_to_end(&lst, ft_lstnew(temp[index], ft_strlen(temp[index]) + 1));
		index++;
	}
	ft_free_two_dimensional_array((void **)temp);
	free(file);
	return (lst);
}

t_list *get_operators(void)
{
	void *file;
	size_t size;
	char end;

	file = reading(&size);
	end = '\0';
	file = ft_memjoin_free_1(file, size, &end, 1);
	return (to_lst(file));
}

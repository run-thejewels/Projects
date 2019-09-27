/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 18:19:22 by kbethany          #+#    #+#             */
/*   Updated: 2019/07/19 18:19:48 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_plst	*ft_choose(t_plst *la, t_plst *lb, t_plst *sol)
{
	t_plst	*cur;

	cur = ft_pslstnew();
	if (ft_issortasc(la))
	{
		if (la->len < 20)
		{
			cur = ft_dyn_resolve(la);
			ft_dyn_copy(cur, sol);
			ft_lstdelallnodes(cur);
		}
		cur = ft_sortmin(la, lb, cur);
		if (sol->head != NULL && cur->len < sol->len)
			ft_dyn_copy(cur, sol);
		else if (sol->head == NULL)
			ft_dyn_copy(cur, sol);
		ft_lstdelallnodes(cur);
	}
	free(cur);
	return (sol);
}

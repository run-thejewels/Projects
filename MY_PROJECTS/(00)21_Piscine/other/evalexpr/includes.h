/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:17:07 by kbethany          #+#    #+#             */
/*   Updated: 2018/10/07 17:15:53 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

char	*re_spaces(char *str);
void	ft_putchar(char a);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
int		high_oper(char *str);
int		low_oper(char *str);
int		eval_expr(char *str);
int		do_op(int a1, int a2, char oper);
int		ft_atoi(char *str);
int		ft_strlen(char *str);

#endif

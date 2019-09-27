/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obertka.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbethany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:56:32 by kbethany          #+#    #+#             */
/*   Updated: 2019/04/18 18:04:12 by kbethany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

int	obertka(t_flag *flag)
{
  char a;
    int  len;
	size_t	s;
	char	*x;

  x = NULL;
  len = ft_strlen(flag->str);
  if (flag->after_dot && flag->flag_5 == 's' && flag->after_dot < len)
      flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->after_dot, 1);
  if (len >= flag->before_dot)
        return (0);
	s = flag->before_dot - len;
	if (flag->after_dot && flag->after_dot - len > 0)
		s = flag->after_dot - len;
	x = ft_strfilnew(s, ' ');
	if (flag->min)
		flag->str = ft_str_fix_width_of_line(flag->str, ' ', s + len, 0);
	else
    {
        if (flag->null)
        {
            if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X'))
                || *(flag->str) == '+' || *(flag->str) == '-')
            {
              if (*(flag->str) == '+' || *(flag->str) == '-')
              {
                a = *(flag->str);
                flag->str = ft_str_fix_width_of_line(flag->str, '0', s + len, 0);
                flag->str = ft_strjoin(&a, flag->str);
              }
              else
              {
                flag->str = ft_str_fix_width_of_line(flag->str + 2, ' ', s + len, 0);
                if (flag->flag_5 == 'X')
                  flag->str = ft_strjoin("0X", flag->str);
                else
                  flag->str = ft_strjoin("0x", flag->str);
                free(x);
              return (0);
              }
            }
        }
        flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->after_dot, 1);
    }
    free(x);
    return (0);
}

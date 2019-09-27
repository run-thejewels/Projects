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

void	fixer_str(t_flag *flag)
{
  int  len;

  len = ft_strlen(flag->str);
  if (flag->after_dot && flag->after_dot < len)
  {
      flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->after_dot, "crop: end");
      len = flag->after_dot;
  }
  if (len < flag->before_dot)
  {
    if (flag->min)
      flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: right, crop: no");
    else if (flag->null)
      flag->str = ft_str_fix_width_of_line(flag->str, '0', flag->before_dot, "alignment: left, crop: no");
    else
      flag->str = ft_str_fix_width_of_line(flag->str, ' ', flag->before_dot, "alignment: left, crop: no");
  }
}


int	fixer_num(t_flag *flag)
{
  size_t s;
  char a;
  int  len;

  len = ft_strlen(flag->str);
  if (len >= flag->before_dot)
        return (0);
  if (len > flag->after_dot)
    flag->after_dot = 0;
  if( flag->after_dot > flag->before_dot)
  {
    flag->before_dot = flag->after_dot;
    flag->after_dot = 0;
    if (flag->flag_5 == 'd' || flag->flag_5 == 'u' || flag->flag_5 == 'D' ||
    flag->flag_5 == 'U' || flag->flag_5 == 'o' || flag->flag_5 == 'x' ||
    flag->flag_5 == 'X' || flag->flag_5 == 'O')
      flag->null = 1;
  }
	s = flag->before_dot;
  if (flag->min && flag->null)
      flag->str = ft_str_fix_width_of_line(flag->str, '0', s, "alignment: right, crop: no");
	else if (flag->min && !(flag->null))
    flag->str = ft_str_fix_width_of_line(flag->str, ' ', s , "alignment: right, crop: no");
	else if (flag->null && !(flag->min))
  {
    if ((flag->sharp && (flag->flag_5 == 'x' || flag->flag_5 == 'X'))
    || *(flag->str) == '+' || *(flag->str) == '-')
    {
      if (*(flag->str) == '+' || *(flag->str) == '-')
      {
        a = *(flag->str);
        flag->str = ft_str_fix_width_of_line(flag->str + 1, '0', s - 1,"alignment: left, crop: no");
        flag->str = ft_strjoin_free_1(ft_strdup_n(&a, 1), flag->str);
      }
      else
      {
        flag->str = ft_str_fix_width_of_line(flag->str + 2 , '0', s - 2, "alignment: left, crop: no");
        if (flag->flag_5 == 'X')
          flag->str = ft_strjoin_free_2("0X", flag->str);
        else
          flag->str = ft_strjoin_free_2("0x", flag->str);
        return (0);
      }
    }
    else
      flag->str = ft_str_fix_width_of_line(flag->str, '0', s,"alignment: left, crop: no");
  }
  else
    flag->str = ft_str_fix_width_of_line(flag->str, ' ', s ,"alignment: left, crop: no");
  return (0);
}

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "libft.h"

typedef struct  s_printf
{
    va_list     ap;
    char        *format;
    char        flag;
    char		*form;
    int         width;
    int         precision;
    int         type;
}               t_printf;

size_t just_to_print_len(char *str, int *persent_indicate, int *count)
{
	size_t index;

	index = 0;
	while (str[index] && str[index] != '%')
		index++;
	if (str[index] == '%')
	{
		*persent_indicate = 1;

	}
	else
		*persent_indicate = 0;
	//index--;
	*count += index;
	//printf("\n count: %d index: %d\n", *count, (int)index);
	return (index);
}

char *ft_putstr_len(char *str, size_t len)
{
	write(1, str, len);
	if (!len)
		return (NULL);
	return (str + len);
}


/*size_t recognise_types(char *str, va_list arguments)
{
	return 3;
}
*/

int		ft_pow(int nb, int pow)
{
	if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}

char	*ft_itoa_base(int value, int base)
{
	int		i;
	char	*nbr;
	int		neg;

	i = 1;
	neg = 0;
	if (value < 0)
	{
		if (base == 10)
			neg = 1;
		value *= -1;
	}
	while (ft_pow(base, i) - 1 < value)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i + neg] = '\0';
	while (i-- > 0)
	{
		nbr[i + neg] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

char	type(char a)
{
	if ( a == 'd' || a == 'i' || a == 'o' ||
		 a == 'u' || a == 'x' || a == 'X' ||
		 a == 'f' || a == 'F' || a == 'c' ||
		 a == 's' || a == 'S' || a == 'p' ||
		 a == '%')
		return (a);
	return (0);
}

char	flag(char a)
{
	if (a == '+' || a == '-' || a == ' ' || a == '0' || a == '#')
		return (a);
	return (0);
}

size_t diglen(int a)
{
	size_t	i;

	i = 0;
	while (a > 9)
	{
		a = a / 10;
		i++;
	}
	return (i);
}

char *form(char *a)
{
	if (ft_strncmp("l", a, 1))
		return ("l");
	if (ft_strncmp("ll", a, 2))
		return ("ll");
	if (ft_strncmp("L", a, 1))
		return ("L");
	if (ft_strncmp("h", a, 1))
		return ("h");
	if (ft_strncmp("hh", a, 2))
		return ("hh");
	return (0);
}

int ft_puter(va_list *arguments,t_printf s)
{
    int     c;
    char    *t;
	wchar_t	*f;

    c = 0;
    t = 0;
    if (s.type == 'd' || s.type == 'i')
    {
        c = va_arg(*arguments, int);
        ft_putnbr(c);
    }
    if (s.type == 'o')
    {
        c = va_arg(*arguments, int);
        t = ft_itoa_base(c, 8);
        ft_putstr(t);
    }
    if (s.type == 'X' || s.type == 'x')
    {
        c = va_arg(*arguments, int);
        t = ft_itoa_base(c, 16);
        ft_putstr(t);
    }
    if (s.type == 'c')
    {
        c = va_arg(*arguments, int);
        ft_putchar(c);
    }
    if (s.type == 's' || s.type == 'S')
    {
        f = va_arg(*arguments, wchar_t*);
		while (*f)
		{
			write(1, &f, 1);
			f++;
		}
    }
    return (0);
}

char *post_persent(char *str, va_list *arguments, int *count, t_printf s)
{
	size_t type_len;
	
	type_len = 0;
	while (!(type(*(str + type_len))))
	{
		if (flag(*str))
		{
			s.flag = flag(*str + type_len);
			type_len++;
		}
		if (ft_isdigit(*(str + type_len)))
		{
			s.width = ft_atoi(str + type_len);
			type_len += diglen(s.width);
		}
		if (*(str + type_len) == '.')
		{
			type_len++;
			s.precision = ft_atoi(str + type_len);
            type_len += diglen(s.precision);
		}
		if (form(str + type_len))
		{
			s.form = form(str + type_len);
			type_len += ft_strlen(s.form);
		}
	}
	s.type = type(*(str + type_len));
	type_len++;
	ft_puter(arguments, s);
	*count += type_len;
	return (str + type_len);
}

int ft_printf(const char *format, ...)
{
	char		*str;
	int			persent_indicate;
	va_list 	arguments;
	t_printf	s;
	int			count;

    s.format = 0;
    s.flag = 0;
    s.form = 0;
    s.width = 0;
    s.precision = 0;
    s.type = 0;
	count = 0;
	str = (char *)format;
	va_start(arguments, format);
	//va_arg(arguments, int);
	while (str)
	{
		//current_argument = va_arg(arguments, char *);
		str = ft_putstr_len(str, just_to_print_len(str, &persent_indicate, &count));

		if (persent_indicate)
			str = post_persent(str, &arguments, &count, s);
		//va_arg(arguments, int);
	}
	va_end(arguments);
	return (count);
}

int main()
{
	int c1;
	int c2;
	char *str = "1234567890 %c 1234567890 %s1234567890\n";
	char t = 't';
	c1 = ft_printf(str, t, "sssssssss");
	c2 = printf(str, t, "sssssssss");
	printf("%d %d\n", c1, c2);
	return 0;
}

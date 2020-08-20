#include "fdf.h"

int	x_count(char *str)
{
	int		index;
	int		word_indicate;
	int		result;

	index = 0;
	word_indicate = 0;
	result = 0;
	while (str[index])
	{
		if (str[index] != ' ')
			word_indicate = 1;
		if (str[index] == ' ' && word_indicate != 0)
		{
			result++;
			word_indicate = 0;
		}
		index++;
	}
	if (word_indicate)
		result++;
	return (result);
}

float max_f(float a, float b)
{
  if (a < 0)
    a *= -1;
  if (b < 0)
    b *= -1;
  if (a > b)
    return (a);
  else
    return (b);
}

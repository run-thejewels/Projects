/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 12:46:24 by rymuller          #+#    #+#             */
/*   Updated: 2019/06/22 17:15:07 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

static int	partition(int *arr, int low, int high, char asc)
{
	int		i;
	int		j;
	int		pivot;

	i = low - 1;
	pivot = arr[high];
	j = low - 1;
	while (++j <= high - 1)
	{
		if (asc && (arr[j] <= pivot))
		{
			i++;
			swap(arr + i, arr + j);
		}
		else if (!asc && (arr[j] >= pivot))
		{
			i++;
			swap(arr + i, arr + j);
		}
	}
	swap(arr + i + 1, arr + high);
	return (i + 1);
}

void		quicksort(int *arr, int low, int high, char asc)
{
	int		pi;

	if (low < high)
	{
		pi = partition(arr, low, high, asc);
		quicksort(arr, low, pi - 1, asc);
		quicksort(arr, pi + 1, high, asc);
	}
}

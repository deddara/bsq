/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finder.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:09:45 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 19:48:35 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	if (b <= a && b <= c)
		return (b);
	else
		return (c);
}

void	check_column(int *size, int **arr, int *data)
{
	int i;

	i = 0;
	while (i < size[0])
	{
		if (arr[i][0] == 1)
		{
			data[0] = 1;
			data[1] = 0;
			data[2] = i;
		}
		i++;
	}
}

void	check_line(int *size, int **arr, int *data)
{
	int i;

	i = 0;
	while (i < size[1])
	{
		if (arr[0][i] == 1 && !data[0])
		{
			data[0] = 1;
			data[1] = 0;
			data[2] = i;
		}
		i++;
	}
}

void	check_other(int *size, int **arr, int *data)
{
	int i;
	int j;
	int t;

	i = 1;
	while (i < size[0])
	{
		j = 1;
		while (j < size[1])
		{
			if (arr[i][j] == 0 && ++j)
				continue;
			t = ft_min(arr[i - 1][j], arr[i - 1][j - 1], arr[i][j - 1]);
			arr[i][j] = t + 1;
			if (arr[i][j] > data[0])
			{
				data[0] = arr[i][j];
				data[1] = i;
				data[2] = j;
			}
			j++;
		}
		i++;
	}
}

int		*max_size(int **arr, int *size)
{
	int *data;

	data = (int*)malloc(sizeof(int) * 5);
	data[0] = 0;
	check_column(size, arr, data);
	check_line(size, arr, data);
	check_other(size, arr, data);
	data[3] = size[0];
	data[4] = size[1];
	return (data);
}

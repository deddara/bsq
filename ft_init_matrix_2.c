/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_matrix_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:42:40 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 21:13:48 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	cut_array(int **matrix, int width)
{
	int *prev_array;
	int *new_array;
	int i;

	i = 0;
	prev_array = matrix[0];
	new_array = (int*)malloc(sizeof(int) * width);
	while (i < width)
	{
		new_array[i] = prev_array[i];
		i++;
	}
	*matrix = new_array;
	free(prev_array);
}

void	enhance_matrix(int **matrix, int *size)
{
	int new_size;
	int *new_array;
	int *prev_array;
	int i;

	prev_array = matrix[0];
	new_size = *size * 2;
	new_array = (int*)malloc(sizeof(int) * new_size);
	i = 0;
	while (i < *size)
	{
		new_array[i] = prev_array[i];
		i++;
	}
	matrix[0] = new_array;
	free(prev_array);
	*size = new_size;
}

void	init_vars(int **crd, int ***matrix, int *size, int *arr_size)
{
	*crd = (int*)malloc(sizeof(int) * 3);
	*matrix = (int**)malloc(sizeof(int*) * size[0]);
	(*crd)[0] = 0;
	(*crd)[1] = 0;
	*arr_size = 32;
	(*matrix)[0] = (int*)malloc(sizeof(int) * (*arr_size));
}

void	print_and_free(int **matrix, int *size, char *chars, int *crd)
{
	print_out(matrix, max_size(matrix, size), chars);
	free(size);
	free(crd);
}

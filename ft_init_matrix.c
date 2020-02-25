/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 20:25:41 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 21:17:32 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		push_to_matrix(char *buf, char *chars, int **matrix, int *crd)
{
	if (*buf == chars[0])
		matrix[crd[0]][crd[1]++] = 1;
	else if (*buf == chars[1])
		matrix[crd[0]][crd[1]++] = 0;
	else if (error())
		return (0);
	return (1);
}

int		read_text(int fd, char *buf, int *read_cnt)
{
	*read_cnt = read(fd, buf, 1);
	if ((*read_cnt) == 0 && error())
		return (0);
	return (1);
}

void	enhance(int *crd, int *size, int *arr_size, int **matrix)
{
	if (crd[0] == 0)
		size[1]++;
	if (crd[0] == 0 && crd[1] >= *arr_size)
		enhance_matrix(matrix, arr_size);
}

int		check_nl(char *buf, int *crd, int **matrix, int *size)
{
	if (*buf == '\n' && ++crd[0] && crd[1] == size[1])
	{
		crd[1] = 0;
		if (crd[0] == 1)
			cut_array(matrix, size[1]);
		if (crd[0] < size[1])
			matrix[crd[0]] = (int*)malloc(sizeof(int) * size[1]);
		return (2);
	}
	else if (*buf == '\n' && crd[0] != 0 && crd[1] != size[1] && error())
		return (0);
	else if (crd[0] > 0 && crd[1] >= size[1] && error())
		return (0);
	return (1);
}

void	init_matrix(int *size, char *chars, int fd)
{
	int		*crd;
	int		**matrix;
	char	buf;
	int		read_cnt;
	int		arr_size;

	init_vars(&crd, &matrix, size, &arr_size);
	while (crd[0] < size[0])
	{
		if (read_text(fd, &buf, &read_cnt) == 0)
			return ;
		crd[2] = check_nl(&buf, crd, matrix, size);
		if (crd[2] == 2)
			continue ;
		else if (!crd[2])
			return ;
		if (push_to_matrix(&buf, chars, matrix, crd) == 0)
			return ;
		enhance(crd, size, &arr_size, matrix);
	}
	if (read(fd, &buf, 1) && error())
		return ;
	print_and_free(matrix, size, chars, crd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:59:34 by deddara           #+#    #+#             */
/*   Updated: 2020/02/25 19:50:52 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

/*
** data[1] - координаты x
** data[2] - координаты y
** data[3] - height
** data[4] - width
** symb[0] - empty
** symb[1] - obctacle
** symb[2] - full
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_out(int **matrix, int *data, char *chars)
{
	int i;
	int j;

	i = 0;
	while (i < data[3])
	{
		j = 0;
		while (j < data[4])
		{
			if (i <= data[1] && i > data[1] - data[0]
			&& j <= data[2] && j > data[2] - data[0])
				ft_putchar(chars[2]);
			else if (matrix[i][j] == 0)
				ft_putchar(chars[1]);
			else
				ft_putchar(chars[0]);
			j++;
		}
		free(matrix[i]);
		ft_putchar('\n');
		i++;
	}
	free(matrix);
	free(data);
	free(chars);
}

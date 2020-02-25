/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:11:20 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 21:13:14 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>

int		ft_atoi(char *str);
int		*max_size(int **arr, int *size);
void	print_out(int **matrix, int *data, char *chars);
void	init_matrix(int *size, char *chars, int fd);
int		error(void);
void	cut_array(int **matrix, int width);
void	enhance_matrix(int **matrix, int *size);
void	init_vars(int **crd, int ***matrix, int *size, int *arr_size);
void	print_and_free(int **matrix, int *size, char *chars, int *crd);

#endif

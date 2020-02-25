/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:49:21 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 20:27:59 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		error(void)
{
	write(2, "map error\n", 10);
	return (1);
}

void	init(int fd, char *init_str, int buf_size)
{
	int		*size;
	char	*chars;

	size = (int*)malloc(sizeof(int) * 2);
	chars = (char*)malloc(sizeof(char) * 3);
	if (((buf_size < 4) || (init_str[buf_size] != '\n')) && error())
		return ;
	chars[0] = init_str[buf_size - 3];
	chars[1] = init_str[buf_size - 2];
	chars[2] = init_str[buf_size - 1];
	init_str[buf_size - 3] = '\0';
	size[0] = ft_atoi(init_str);
	free(init_str);
	size[1] = 0;
	if (!size[0] && error())
		return ;
	init_matrix(size, chars, fd);
}

void	bsq(int fd)
{
	char	*data;
	char	buf;
	int		read_cnt;
	int		i;

	errno = 0;
	data = malloc(sizeof(char) * 32);
	if (errno && error())
		return ;
	i = 0;
	read_cnt = read(fd, &buf, 1);
	while (buf != '\n' && read_cnt != 0)
	{
		if (errno && error())
			return ;
		data[i++] = buf;
		read_cnt = read(fd, &buf, 1);
	}
	data[i] = buf;
	init(fd, data, i);
}

int		main(int ac, char **av)
{
	int i;
	int fd;

	if (ac <= 1)
	{
		bsq(0);
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			fd = open(av[i], O_RDONLY);
			bsq(fd);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}
}

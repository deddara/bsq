/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deddara <deddara@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:53:01 by deddara           #+#    #+#             */
/*   Updated: 2020/02/24 22:10:49 by deddara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdio.h"
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void error(void)
{
	write(2, "map error\n", 10);
}

int	file_reader(char *argv)
{
	int fd;
	int size;
	char symb;
	char *array;
	int i = 0;

	size = 0;
	fd = open(argv, O_RDONLY);		//открываем файл
	while(read(fd, &symb, 1))		//считаем в нем символов,чтобы потом создать массив и записать туда значения верхней строчки
		size++;
	array = (char*)malloc(sizeof(char) * (size + 1 ));	//выделяем память
	fd = open(argv, O_RDONLY);	//снова открываем файл, чтобы могли повторно считать (при этом закрывать его не обязательно)

	// здесь будет вывалена в кучу проверка на валидность первой строки и сохпанение ее значений в массив
	while(read(fd, &symb, 1))
	{
		array[i] = symb;
		i++;
	}
	if(array[0] < '0' || array[0] > '9') //если первый символ не цифра - то ошибка
	{
		error();
		return (0);
	}
	i = 0;
	while(array[i] >= '0' && array[i] <= '9') // сначала могут быть только цифры, пропускаем их
		i++;
	if (array[i] == '\n')	//если мы пропустили все цифры и дошли до конца строчки - строка не валидна
	{
		error();
		return (0);
	}
	size = 0;	//обыный счетчик
	while(array[i] != '\n')		//пока не дойдем до конца пропускаем симыволы и считаем счетчик
	{
		size++;
		i++;
	}
	if(size != 3)		//после цифр может быть только 3 символа, если наш счетчик не равен трем, значит символов больше - не валидность
	{
		error();
		return (0);
	}
	// конец проверки на валидность первой строки
	return(1);
}

int		file_validator(int argc, char **argv)
{
	char c;
	int j;
	int val;

	j = 1;
	while (j < argc)
	{
		file_reader(argv[j]);	//функция для открытия и считывания файла
		j++;
	}
	return(0);
}


int	main(int argc, char **argv)
{
	char c;
	file_validator(argc, argv);	//просто функция
	return (0);
}

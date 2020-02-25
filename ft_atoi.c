/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olaurine <olaurine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 15:09:21 by olaurine          #+#    #+#             */
/*   Updated: 2020/02/25 18:23:07 by olaurine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		ft_check_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	if (c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int number;
	int minus;

	number = 0;
	minus = 1;
	while (ft_check_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		minus = *str == '-' ? -1 : 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * minus);
}

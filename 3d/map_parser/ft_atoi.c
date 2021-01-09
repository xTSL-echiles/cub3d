/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:56:06 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:18:11 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libcub.h"

int	ft_atoi(const char *nptr)
{
	long		int	znak;
	long		int	result;
	unsigned	int	i;

	i = 0;
	znak = 1;
	result = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 14) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		znak = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		if (result > 2147483648 && nptr[i] > '7')
			return (znak > 0 ? -1 : 0);
		i++;
	}
	return ((int)result * znak);
}

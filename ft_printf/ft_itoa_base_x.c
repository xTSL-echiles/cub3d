/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:16:02 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:16:09 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow(unsigned int nb, int pow)
{
	int j;

	j = 0;
	if (pow == 0)
		return (1);
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb = nb / pow;
		j++;
	}
	return (j);
}

char	*ft_itoa_base_x(unsigned int value, int base)
{
	int		i;
	char	*nbr;

	i = 1;
	i = ft_pow(value, base);
	nbr = (char*)malloc(sizeof(char) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}

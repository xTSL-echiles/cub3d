/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:14:19 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:15:22 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_pow1(unsigned long long int nb, unsigned long long int pow)
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

char	*ft_itoa_base_p(unsigned long long int value, int base)
{
	int		i;
	char	*nbr;

	i = 1;
	i = ft_pow1(value, (unsigned long long)base);
	nbr = (char*)malloc(sizeof(char) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'a' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}

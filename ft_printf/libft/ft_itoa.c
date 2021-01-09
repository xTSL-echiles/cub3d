/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:25:37 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:29:34 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_size(long int n1)
{
	unsigned int i;

	i = 0;
	if (n1 <= 0)
		i++;
	while (n1 != 0)
	{
		i++;
		n1 = n1 / 10;
	}
	return (i);
}

char	*ft_itoa(long int n)
{
	long int	nb;
	char		*str;
	size_t		size;

	nb = n;
	size = ft_size(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == 0)
		return (NULL);
	str[size] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = nb * -1;
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb != 0)
	{
		str[size - 1] = nb % 10 + '0';
		nb = nb / 10;
		size--;
	}
	return (str);
}

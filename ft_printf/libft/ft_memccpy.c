/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:33:59 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:30:35 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*pst;
	size_t			i;

	i = 0;
	cpy = (unsigned char*)src;
	pst = (unsigned char*)dest;
	while (i < n)
	{
		pst[i] = cpy[i];
		if (cpy[i] == (unsigned char)c)
		{
			return (pst + i + 1);
		}
		i++;
	}
	return (NULL);
}

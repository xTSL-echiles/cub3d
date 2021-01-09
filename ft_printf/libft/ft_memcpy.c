/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:11:57 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:36:39 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy;
	char	*pst;

	cpy = (char*)dest;
	pst = (char*)src;
	if (n <= 0 || cpy == pst)
		return (dest);
	while (n > 0)
	{
		*cpy++ = *pst++;
		n--;
	}
	return (dest);
}

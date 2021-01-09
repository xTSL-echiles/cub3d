/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:12:23 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:37:26 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cpy;
	char	*pst;

	if (src == dest)
		return (dest);
	cpy = (char *)src;
	pst = (char *)dest;
	if (src < dest)
	{
		while (n > 0)
		{
			n--;
			pst[n] = cpy[n];
		}
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

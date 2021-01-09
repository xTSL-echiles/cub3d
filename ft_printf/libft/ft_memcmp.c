/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:13:45 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:35:49 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*pst;

	cpy = (unsigned char*)s1;
	pst = (unsigned char*)s2;
	if (s1 == s2)
		return (0);
	while (n > 0)
	{
		if (*cpy != *pst)
		{
			return (*cpy - *pst);
		}
		n--;
		cpy++;
		pst++;
	}
	return (0);
}

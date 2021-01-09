/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:37:44 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:58:52 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libcub.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pst;

	pst = malloc(size * count);
	if (pst == 0)
		return (NULL);
	ft_bzero(pst, size * count);
	return (pst);
}

void	*ft_bzero(void *s, size_t n)
{
	size_t			i1;
	unsigned char	*r;

	r = (unsigned char*)s;
	i1 = 0;
	while (i1 < n)
	{
		r[i1] = 0;
		i1++;
	}
	return (s);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:42:28 by echiles           #+#    #+#             */
/*   Updated: 2020/11/06 14:48:31 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*pst;
	size_t	size;

	size = ft_strlen((char*)s1) + 1;
	pst = malloc(size);
	if (pst == NULL)
		return (NULL);
	ft_memcpy(pst, s1, size);
	return (pst);
}

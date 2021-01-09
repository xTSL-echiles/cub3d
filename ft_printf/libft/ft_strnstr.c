/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:19:59 by echiles           #+#    #+#             */
/*   Updated: 2020/11/06 15:24:10 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i] == small[j] &&
				big[i] != '\0' && small[j] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (small[j] == '\0' && i - j <= len)
			return ((char*)big + i - j);
		i--;
	}
	return (0);
}

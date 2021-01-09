/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:17:18 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:51:46 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*b;

	b = (char*)s;
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == c)
		{
			return (&b[i]);
		}
		i++;
	}
	if (c == '\0')
		return (&b[i]);
	return (NULL);
}
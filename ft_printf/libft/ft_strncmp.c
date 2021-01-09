/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:20:32 by echiles           #+#    #+#             */
/*   Updated: 2020/11/06 15:46:25 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	if (len == 0)
		return (0);
	if (s2[i] == 0 || s1[i] == 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	while (s2[i] != '\0' && i < len && s1[i] != '\0')
	{
		if (s1[i] != s2[i] && s2[i] != '\0' && s1[i] != '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (i < len && s1[i] == '\0')
		return (0 - (unsigned char)s2[i]);
	if (i < len && s2[i] == '\0')
		return ((unsigned char)s1[i] - 0);
	return (0);
}

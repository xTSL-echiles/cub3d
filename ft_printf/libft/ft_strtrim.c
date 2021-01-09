/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:09:08 by echiles           #+#    #+#             */
/*   Updated: 2020/11/06 14:45:15 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	size;

	if (s1 == 0)
		return (NULL);
	while (*s1 && ft_strrchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strrchr(set, s1[size]))
		size--;
	res = (char*)malloc(sizeof(char) * (size + 2));
	ft_strlcpy(res, s1, size + 2);
	return (res);
}

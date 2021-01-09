/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 15:53:26 by echiles           #+#    #+#             */
/*   Updated: 2020/11/04 15:54:52 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	size;

	if (s1 == 0 || s2 == 0)
		return (NULL);
	size = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 2;
	res = malloc(size);
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s1, (ft_strlen((char*)s1)) + 1);
	ft_strlcat(res, s2, size);
	return (res);
}

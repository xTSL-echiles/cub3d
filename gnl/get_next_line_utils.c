/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:55:14 by echiles           #+#    #+#             */
/*   Updated: 2020/12/01 12:55:17 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s, char c)
{
	size_t i;

	i = 0;
	while (s && s[i] != c)
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*b;

	b = (char*)s;
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == c)
			return (&b[i]);
		i++;
	}
	if (b[i] == c)
		return (&b[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1, '\0') + ft_strlen(s2, '\0') + 1;
	if (!(res = malloc(sizeof(char) * size)))
		return (0);
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[j + i] = '\0';
	free(s1);
	s1 = NULL;
	return (res);
}

char	*ft_strdup(const char *s1, char c)
{
	char				*dst;
	int					i;
	unsigned long		len;

	len = ft_strlen(s1, c);
	i = 0;
	if (!(dst = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] != c && s1)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:10:35 by echiles           #+#    #+#             */
/*   Updated: 2020/11/09 15:43:22 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

char	*ft_strcpy(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(src, '\0');
	dest = malloc(sizeof(char) * (j + 1));
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pst;
	unsigned int	i;
	unsigned int	k;

	if (s == 0)
		return (NULL);
	k = 0;
	i = 0;
	k = ft_strlen(s, '\0');
	if (start >= k)
		return (ft_calloc(1, 1));
	if (k - start > len)
		k = len;
	else
		k = k - start;
	pst = malloc(sizeof(char) * k + 1);
	if (pst == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		pst[i] = s[i + start];
		i++;
	}
	pst[i] = '\0';
	return (pst);
}

int		ft_garbage_check(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'R')
			return (1);
		else if (line[i] == 'N' && line[i + 1] == 'O')
			return (1);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			return (1);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			return (1);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			return (1);
		else if (line[i] == 'S')
			return (1);
		else if (line[i] == 'F' || line[i] == 'C')
			return (1);
		else if (line[i] != 32)
			break ;
		i++;
	}
	return ((!(line[i]) ? 1 : 0));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:10:35 by echiles           #+#    #+#             */
/*   Updated: 2020/11/20 13:11:15 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pst;
	unsigned int	i;
	unsigned int	k;

	if (s == 0)
		return (NULL);
	k = 0;
	i = 0;
	while (s[k] != '\0')
		k++;
	if (k - start > len)
		k = len;
	if (start >= k)
		return (ft_calloc(1, 1));
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

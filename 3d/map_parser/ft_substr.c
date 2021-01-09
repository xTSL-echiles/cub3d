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

#include "../headers/libcub.h"
#include <string.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*pst;
	unsigned int	i;
	unsigned int	k;

	if (s == 0)
		return (NULL);
	k = 0;
	i = 0;
	k = strlen(s);  // не забыть разобраться в чем дело
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

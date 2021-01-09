/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 14:43:04 by echiles           #+#    #+#             */
/*   Updated: 2020/11/05 12:21:49 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libcub.h"

int		ft_count(const char *s1, char c1)
{
	int	i1;
	int	w;

	w = 0;
	i1 = 0;
	while (s1[i1] != '\0')
	{
		while (s1[i1] == c1)
			i1++;
		if (s1[i1] != '\0')
			w++;
		while (s1[i1] && (s1[i1] != c1))
			i1++;
	}
	return (w);
}

int		ans_check(char **s2, int n1)
{
	if (s2[n1] == 0 && n1 >= 0)
	{
		while (n1 != -1)
		{
			free(s2[n1]);
			n1--;
		}
		free(s2);
		return (0);
	}
	return (1);
}

char	**ft_record(char **ans1, const char *str, char c2)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		while (str[i] == c2)
			i++;
		j = i;
		while (str[i] != '\0' && str[i] != c2)
			i++;
		if (i > j)
		{
			ans1[n] = ft_substr(str, j, i - j);
			if (ans_check(ans1, n) != 1)
				return (0);
			n++;
		}
	}
	ans1[n] = 0;
	return (ans1);
}

char	**ft_split(char const *s, char c)
{
	char **ans;

	if (s == 0)
		return (NULL);
	ans = (char**)malloc(sizeof(char*) * ft_count(s, c) + 1);
	if (ans == 0)
		return (NULL);
	ft_record(ans, s, c);
	return (ans);
}

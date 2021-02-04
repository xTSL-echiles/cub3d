/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_zero_line_in_map.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:54:34 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 12:54:35 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_check_save(char *save)
{
	int i;

	i = 0;
	if ((ft_strrchr(save, '1')) != NULL)
		i++;
	else if ((ft_strrchr(save, '0')) != NULL)
		i++;
	else if ((ft_strrchr(save, '2')) != NULL)
		i++;
	else if ((ft_strrchr(save, 'N')) != NULL)
		i++;
	else if ((ft_strrchr(save, 'S')) != NULL)
		i++;
	else if ((ft_strrchr(save, 'W')) != NULL)
		i++;
	else if ((ft_strrchr(save, 'E')) != NULL)
		i++;
	return ((i > 0) ? 1 : 0);
}

int		ft_check_0_line_in_map(char *save, char *line)
{
	if (ft_check_save(save) && line[0] == '\n')
	{
		free(save);
		save = NULL;
		return (0);
	}
	return (1);
}

int		ft_check_color_p2(t_options *qu, int i, char **ans, char c)
{
	if ((ft_strrchr(ans[0], c) != NULL) &&
	(qu->fr == -1 && qu->fg == -1 && qu->fb == -1))
	{
		qu->fr = ft_atoi(&ans[0][i]);
		qu->fg = ft_atoi(ans[1]);
		qu->fb = ft_atoi(ans[2]);
		return (100100);
	}
	if (ft_strrchr(ans[0], c) != NULL &&
	(qu->cr == -1 && qu->cg == -1 && qu->cb == -1))
	{
		qu->cr = ft_atoi(&ans[0][i]);
		qu->cg = ft_atoi(ans[1]);
		qu->cb = ft_atoi(ans[2]);
		return (100100);
	}
	return (0);
}

int		ft_check_line_for_split(char *line)
{
	int j;
	int i;

	i = -1;
	j = 0;
	while (line && line[++i])
	{
		if (line[i] == ',')
			j++;
	}
	return (j);
}

int		ft_check_nubmers(char *s)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (s && s[k])
	{
		if (s[k] == 0)
			j++;
		k++;
	}
	return ((k > 10) ? 2147483647 : 0);
}

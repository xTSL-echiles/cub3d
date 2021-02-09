/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acces.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:52:36 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 12:52:41 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_acces_checker(t_options *qu)
{
	if (qu->acces == 0)
	{
		if ((qu->rheig_y > 0) && (qu->rwid_x > 0) &&
		qu->no != NULL && qu->so != NULL && qu->we != NULL &&
		qu->ea != NULL && qu->s != NULL && ((qu->fr > -1) && (qu->fr <= 255)) &&
		((qu->fg > -1) && (qu->fg <= 255)) && ((qu->fb > -1) && (qu->fb <= 255))
		&& ((qu->cr > -1) && (qu->cr <= 255)) && ((qu->cg > -1) &&
		(qu->cg <= 255)) && ((qu->cb > -1) && (qu->cb <= 255)))
		{
			if (ft_cptain_prise(qu))
				qu->acces = 2;
			else
				qu->acces = 1;
		}
	}
	if (qu->acces == 2)
		return (2);
	return ((qu->acces == 1) ? 1 : 0);
}

int		check_r(t_options *qu, char *line)
{
	char	**ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ans = ft_split(line, ' ');
	if (ans[0][0] == 'R' && ans[0][1] == '\0')
	{
		while (ans[i] != '\0')
			i++;
		if (i == 3 && ft_check_res(ans, 1, 2))
		{
			if (qu->rwid_x != 0 && qu->rheig_y != 0)
			{
				ft_cleaner_mass(ans);
				return (0);
			}
			qu->rwid_x = ((ft_check_nubmers(ans[1])) ? 50000 : ft_atoi(ans[1]));
			qu->rheig_y = ((ft_check_nubmers(ans[2])) ? 9000 : ft_atoi(ans[2]));
		}
	}
	ft_cleaner_mass(ans);
	return (1);
}

int		check_texture(t_options *qu, char *line, int i, int j)
{
	char	**ans;

	ans = ft_split(line, ' ');
	while (ans[i] != '\0')
		i++;
	if (i == 2)
	{
		if (ans[0][0] == 'E' && ans[0][1] == 'A' && ans[0][2] == '\0'
			&& qu->ea == NULL)
			qu->ea = ft_strcpy(ans[++j]);
		else if (ans[0][0] == 'W' && ans[0][1] == 'E' && ans[0][2] == '\0'
			&& qu->we == NULL)
			qu->we = ft_strcpy(ans[++j]);
		else if (ans[0][0] == 'N' && ans[0][1] == 'O' && ans[0][2] == '\0'
			&& qu->no == NULL)
			qu->no = ft_strcpy(ans[++j]);
		else if (ans[0][0] == 'S' && ans[0][1] == 'O' && ans[0][2] == '\0'
			&& qu->so == NULL)
			qu->so = ft_strcpy(ans[++j]);
		else if (ans[0][0] == 'S' && ans[0][1] == '\0'
			&& qu->s == NULL)
			qu->s = ft_strcpy(ans[++j]);
	}
	ft_cleaner_mass(ans);
	return ((j == 0) ? 0 : 1);
}

int		check_fc(t_options *qu, char *line, int i, char c)
{
	char	**ans;
	int		j;

	j = ft_check_line_for_split(line);
	if (j == 2)
		ans = ft_split(line, ',');
	else
		return (0);
	i = 0;
	while (ans && ans[i] != '\0')
		i++;
	if (i == 3 && ft_color_control(ans, c, 0, -1))
	{
		i = 0;
		while ((!ft_isdigit(ans[0][i])))
			i++;
		if (c == 'F')
			j = ft_check_color_p2(qu, i, ans, c);
		else
			j = ft_check_color_p2(qu, i, ans, c);
	}
	ft_cleaner_mass(ans);
	return ((j == 100100) ? 1 : 0);
}

int		pars_check(t_options *qu, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			return (check_r(qu, line));
		else if (line[i] == 'N' && line[i + 1] == 'O')
			return (check_texture(qu, line, 0, 0));
		else if (line[i] == 'S' && line[i + 1] == 'O')
			return (check_texture(qu, line, 0, 0));
		else if (line[i] == 'W' && line[i + 1] == 'E')
			return (check_texture(qu, line, 0, 0));
		else if (line[i] == 'E' && line[i + 1] == 'A')
			return (check_texture(qu, line, 0, 0));
		else if (line[i] == 'S')
			return (check_texture(qu, line, 0, 0));
		else if (line[i] == 'F' || line[i] == 'C')
			return (check_fc(qu, line, 0, line[i]));
		i++;
	}
	return (ft_garbage_check(line));
}

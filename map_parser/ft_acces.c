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

#include "../headers/libcub.h"

int		ft_acces_checker(t_options *qu)
{
	if (qu->acces == 0)
	{
		if ((qu->Rheig_y > 0) && (qu->Rwid_x > 0) &&
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

void	check_r(t_options *qu, char *line)
{
	char	**ans;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ans = ft_split(line, ' ');
	if (ans[0][0] == 'R')
	{
		while (ans[i] != '\0')
			i++;
		if (i == 3)
		{
			qu->Rwid_x = ft_atoi(ans[1]);
			qu->Rheig_y = ft_atoi(ans[2]);
		}
	}
	ft_cleaner_mass(ans);
}

void	check_texture(t_options *qu, char *line, int i)
{
	char	**ans;

	ans = ft_split(line, ' ');
	while (ans[i] != '\0')
		i++;
	if (i == 2)
	{
		if ((ft_strrchr(ans[0], 'E') != NULL) &&
			(ft_strrchr(ans[0], 'A') != NULL))
			qu->ea = ft_strcpy(ans[1]);
		else if ((ft_strrchr(ans[0], 'W') != NULL) &&
			(ft_strrchr(ans[0], 'E') != NULL))
			qu->we = ft_strcpy(ans[1]);
		else if ((ft_strrchr(ans[0], 'N') != NULL) &&
			(ft_strrchr(ans[0], 'O') != NULL))
			qu->no = ft_strcpy(ans[1]);
		else if ((ft_strrchr(ans[0], 'S') != NULL) &&
			(ft_strrchr(ans[0], 'O') != NULL))
			qu->so = ft_strcpy(ans[1]);
		else if ((ft_strrchr(ans[0], 'S') != NULL) &&
			(ft_strrchr(ans[0], 'O') == NULL))
			qu->s = ft_strcpy(ans[1]);
	}
	ft_cleaner_mass(ans);
}

void	check_fc(t_options *qu, char *line, int i)
{
	char	**ans;

	ans = ft_split(line, ',');
	while (ans[i] != '\0')
		i++;
	if ((i == 3) && !(ft_check_digit_in_colors(ans)))
	{
		while (!ft_isdigit(ans[0][i - 3]))
			i++;
		if (ft_strrchr(ans[0], 'F') != NULL)
		{
			qu->fr = ft_atoi(&ans[0][i - 4]);
			qu->fg = ft_atoi(ans[1]);
			qu->fb = ft_atoi(ans[2]);
		}
		else if (ft_strrchr(ans[0], 'C') != NULL)
		{
			qu->cr = ft_atoi(&ans[0][i - 4]);
			qu->cg = ft_atoi(ans[1]);
			qu->cb = ft_atoi(ans[2]);
		}
	}
	ft_cleaner_mass(ans);
}

int		pars_check(t_options *qu, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'R')
			check_r(qu, line);
		else if (line[i] == 'N' && line[i + 1] == 'O')
			check_texture(qu, line, 0);
		else if (line[i] == 'S' && line[i + 1] == 'O')
			check_texture(qu, line, 0);
		else if (line[i] == 'W' && line[i + 1] == 'E')
			check_texture(qu, line, 0);
		else if (line[i] == 'E' && line[i + 1] == 'A')
			check_texture(qu, line, 0);
		else if (line[i] == 'S')
			check_texture(qu, line, 0);
		else if (line[i] == 'F' || line[i] == 'C')
			check_fc(qu, line, 0);
		i++;
	}
	return (ft_garbage_check(line));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:42:47 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 13:42:49 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void	ft_all_null_now(t_options *qu)
{
	qu->rwid_x = 0;
	qu->rheig_y = 0;
	qu->no = NULL;
	qu->so = NULL;
	qu->we = NULL;
	qu->ea = NULL;
	qu->s = NULL;
	qu->fr = -1;
	qu->fg = -1;
	qu->fb = -1;
	qu->cr = -1;
	qu->cg = -1;
	qu->cb = -1;
	qu->player = 0;
	qu->filename = NULL;
	qu->acces = 0;
	qu->numsprites = 0;
	qu->save_flag = 0;
}

int		ft_check_file_name(char *name, char *s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (name && name[i] != '\0')
		i++;
	if (i > 5)
	{
		if (name[i - 1] == s[3])
			j++;
		if (name[i - 2] == s[2])
			j++;
		if (name[i - 3] == s[1])
			j++;
		if (name[i - 4] == s[0])
			j++;
	}
	return (((j == 4) ? 0 : 1));
}

void	ft_cleaner_mass(char **ans)
{
	int	i;

	i = 0;
	while (ans[i])
	{
		free(ans[i]);
		i++;
	}
	free(ans);
}

int		ft_cptain_prise(t_options *qu)
{
	int fd;
	int i;

	i = 0;
	if ((fd = open(qu->no, O_RDONLY)) < 0)
		i++;
	if ((fd = open(qu->so, O_RDONLY)) < 0)
		i++;
	if ((fd = open(qu->we, O_RDONLY)) < 0)
		i++;
	if ((fd = open(qu->ea, O_RDONLY)) < 0)
		i++;
	if ((fd = open(qu->s, O_RDONLY)) < 0)
		i++;
	close(fd);
	if (i == 0)
	{
		i = ft_check_file_name(qu->no, ".xpm");
		i = ft_check_file_name(qu->so, ".xpm");
		i = ft_check_file_name(qu->we, ".xpm");
		i = ft_check_file_name(qu->ea, ".xpm");
		i = ft_check_file_name(qu->s, ".xpm");
	}
	return ((i > 0) ? 2 : 0);
}

int		ft_check_res(char **ans, int start, int check)
{
	int j;
	int i;

	j = start;
	while (j <= check)
	{
		i = 0;
		while ((ans[j][i]))
		{
			if (!(ft_isdigit(ans[j][i])))
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

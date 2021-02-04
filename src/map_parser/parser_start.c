/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:30:09 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 13:30:10 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../../includes/libcub.h"

int		ft_map_rec(t_options *qu, char *save, char *line)
{
	if (save == NULL)
	{
		free(line);
		free(save);
		return (ft_error_msg("Error: empty map\n"));
	}
	if (save != NULL)
	{
		save = ft_strjoin(save, line);
		qu->map = ft_split(save, '\n');
	}
	free(line);
	free(save);
	return (1);
}

int		ft_read_and_rec(t_options *qu)
{
	int		fd;
	char	*line;
	char	*save;
	int		j;

	save = NULL;
	if ((fd = open(qu->filename, O_RDONLY)) == -1)
		return (ft_error_msg("Cant read map-file\n"));
	while (get_next_line(fd, &line, ((ft_acces_checker(qu)) > 0) ? 1 : 0) > 0)
	{
		j = ((qu->acces == 2) ? 1 : 0);
		if (qu->acces == 1)
		{
			if (!(j = (ft_check_0_line_in_map(save, line) > 0 ? 0 : 1)))
				if (line[0] != '\n')
					save = ft_strjoin(save, line);
		}
		else
			j = ((pars_check(qu, line) > 0) ? 0 : 1);
		free(line);
		if (j == 1)
			return (ft_error_msg("Error: invalid options/empty line in map\n"));
	}
	return ((ft_map_rec(qu, save, line)));
}

int		ft_parser_start(t_data *img, int ar, char **arg)
{
	if (!(img->qu = (t_options*)malloc(sizeof(t_options))))
		return (0);
	ft_all_null_now(img->qu);
	if (!(ft_check_argv(img->qu, arg, ar)))
	{
		free(img->qu);
		return (0);
	}
	if (!(ft_read_and_rec(img->qu)))
	{
		free(img->qu);
		return (0);
	}
	if (!(ft_parser_map(img->qu)))
	{
		ft_cleaner_mass(img->qu->map);
		free(img->qu);
		return (0);
	}
	return (1);
}

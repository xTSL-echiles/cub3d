/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:34:14 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 13:34:19 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_save_check(char **argv)
{
	int		i;
	char	*c;

	if (!(c = ft_strcpy("--save")))
		return (ft_error_msg("Error\nmalloc"));
	i = 0;
	if (ft_strlen(argv[2], '\0') != ft_strlen(c, '\0'))
		return (0);
	while (argv[2][i] != '\0')
	{
		if (argv[2][i] != c[i])
			return (0);
		i++;
	}
	free(c);
	return (2);
}

int		ft_check_argv(t_options *qu, char **argv, int argc)
{
	if ((argc > 2 && argc < 4) && (ft_save_check(argv) > 0))
		qu->save_flag = 1;
	else if (argc > 2)
		return (ft_error_msg(ERROR));
	if (argv[1])
		qu->filename = ft_strcpy(argv[1]);
	else
		return (ft_error_msg("Error\n1st arg need map\n"));
	if (ft_check_file_name(qu->filename, ".cub"))
		return (ft_error_msg("Error\nwrong file name or invalid file\n"));
	return (1);
}

int		ft_error_msg(char *s)
{
	int i;

	i = 0;
	if (s > 0)
	{
		i = 0;
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
	return (0);
}

int		ft_wiev_setup(t_options *qu)
{
	if (qu->player == 'N' || qu->player == 'S')
	{
		qu->view_x = ((qu->player == 'S') ? 1 : -1);
		qu->view_y = 0;
		qu->fov_x = 0;
		qu->fov_y = ((qu->player == 'S') ? -0.7 : 0.7);
	}
	if (qu->player == 'E' || qu->player == 'W')
	{
		qu->view_x = 0;
		qu->view_y = ((qu->player == 'W') ? -1 : 1);
		qu->fov_x = ((qu->player == 'W') ? -0.7 : 0.7);
		qu->fov_y = 0;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:51:37 by echiles           #+#    #+#             */
/*   Updated: 2020/12/01 12:53:48 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int	ft_print_line(char **line, char **save, char spec, int j)
{
	char *find_n;
	char *temp;

	if (spec == '\n')
	{
		if (j > 0)
			*line = ft_strdup1(*save, '\n');
		else
			*line = ft_strdup(*save, '\n');
		find_n = ft_strrchr(*save, '\n');
		find_n++;
		temp = *save;
		*save = ft_strdup(find_n, '\0');
		free(temp);
		return (1);
	}
	if (spec == '\0')
	{
		*line = ft_strdup(*save, '\0');
		free(*save);
		*save = NULL;
	}
	return (0);
}

int	ft_check_line(t_costil *gnl, char **line, char **save, int j)
{
	free(gnl->buf);
	if (gnl->ret <= -1)
	{
		if (*save)
		{
			free(*save);
			*save = NULL;
		}
		return (-1);
	}
	if (!gnl->ret && !*save)
	{
		*line = ft_strdup("", '\0');
		return (0);
	}
	if ((ft_strrchr(*save, '\n')) != NULL)
		return (ft_print_line(line, save, '\n', j));
	else if ((ft_strrchr(*save, '\0')) != NULL)
		return (ft_print_line(line, save, '\0', j));
	return (0);
}

int	get_next_line(int fd, char **line, int j)
{
	t_costil	gnl;
	static char	*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||
		!(gnl.buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while ((gnl.ret = read(fd, gnl.buf, BUFFER_SIZE)) > 0)
	{
		gnl.buf[gnl.ret] = '\0';
		save = ft_strjoin(save, gnl.buf);
		if ((ft_strrchr(save, '\n')) != NULL)
			return (ft_check_line(&gnl, line, &save, j));
	}
	return (ft_check_line(&gnl, line, &save, j));
}

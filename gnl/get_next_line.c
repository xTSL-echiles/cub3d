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

#include "get_next_line.h"

int	ft_print_line(char **line, char **save, char spec)
{
	char *find_n;
	char *temp;

	if (spec == '\n')
	{
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

int	ft_check_line(int ret, char **line, char **save, char **buf)
{
	free(*buf);
	if (ret <= -1)
		return (-1);
	if (!ret && !*save)
	{
		*line = ft_strdup("", '\0');
		return (0);
	}
	if ((ft_strrchr(*save, '\n')) != NULL)
		return (ft_print_line(line, save, '\n'));
	else if ((ft_strrchr(*save, '\0')) != NULL)
		return (ft_print_line(line, save, '\0'));
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if ((ft_strrchr(save, '\n')) != NULL)
			return (ft_check_line(ret, line, &save, &buf));
	}
	return (ft_check_line(ret, line, &save, &buf));
}

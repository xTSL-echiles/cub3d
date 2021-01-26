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

#include "../headers/libcub.h"

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
		write(1, "Error: empty line in map\n", 25);
		free(line);
		free(save);
		line = NULL;
		save = NULL;
		return (0);
	}
	return (1);
}

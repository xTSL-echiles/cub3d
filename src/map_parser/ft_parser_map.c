/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:09:00 by echiles           #+#    #+#             */
/*   Updated: 2021/01/26 13:09:03 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_pars_str_utils(t_options *qu, int i, int j, int k)
{
	if (k == 1)
	{
		if ((qu->map[i][j + 1] != '0' && qu->map[i][j + 1] != '1' &&
		qu->map[i][j + 1] != '2' && qu->map[i][j + 1] != qu->player)
		|| (qu->map[i + 1][j] != '1' && qu->map[i + 1][j] != '0'
		&& qu->map[i + 1][j] != '2' && qu->map[i + 1][j] != qu->player) ||
		(qu->map[i - 1][j] != '1' && qu->map[i - 1][j] != '0'
		&& qu->map[i - 1][j] != '2' && qu->map[i - 1][j] != qu->player) ||
		(qu->map[i][j - 1] != '0' && qu->map[i][j - 1] != '1' &&
		qu->map[i][j - 1] != '2' && qu->map[i][j - 1] != qu->player))
			return (0);
	}
	if (k == 2)
	{
		if (qu->map[i][j] != '0' && qu->map[i][j] != '1' &&
		qu->map[i][j] != '2' && qu->map[i][j] != qu->player &&
		qu->map[i][j] != ' ' && qu->map[i][j] != '\n')
			return (ft_error_msg("Error\ninvalid map\n"));
		if (qu->map[i][j] == '2')
			qu->numsprites++;
	}
	return (1);
}

int		ft_pars_str(t_options *qu, int i)
{
	int	j;
	int	str1;
	int	str2;

	j = 0;
	if (qu->map[i][0] != '1' && qu->map[i][0] != ' ')
		return (0);
	str1 = ft_strlen(qu->map[i - 1], '\0');
	str2 = ft_strlen(qu->map[i + 1], '\0');
	while (qu->map[i][j] != '\0')
	{
		if (!(ft_pars_str_utils(qu, i, j, 2)))
			return (0);
		if (qu->map[i][j] == '0' || qu->map[i][j] == '2' ||
		qu->map[i][j] == qu->player)
		{
			if (j > str2 || str1 <= j)
				return (0);
			if (!(ft_pars_str_utils(qu, i, j, 1)))
				return (0);
		}
		j++;
	}
	return (1);
}

int		ft_check_fst_and_lst(t_options *qu, int i)
{
	int	j;

	j = 0;
	while (qu->map && qu->map[i] && qu->map[i][j] != '\0')
	{
		if (qu->map[i][j] != '1' && qu->map[i][j] != ' ')
			return (ft_error_msg("Error\ninvalid map\n"));
		j++;
	}
	return (1);
}

int		ft_player_pos(t_options *qu)
{
	int i;
	int j;

	i = -1;
	while (qu->map[++i])
	{
		j = -1;
		while (qu->map[i][++j] != '\0')
		{
			if (qu->map[i][j] == 'N' || qu->map[i][j] == 'S' ||
		qu->map[i][j] == 'E' || qu->map[i][j] == 'W')
			{
				if (!qu->player)
				{
					qu->player = qu->map[i][j];
					break ;
				}
				return (ft_error_msg("Error\nmany players position\n"));
			}
		}
	}
	if (!(qu->player))
		return (ft_error_msg("Error\nno player position\n"));
	return (1);
}

int		ft_parser_map(t_options *qu)
{
	int i;

	i = -1;
	while (qu->map && qu->map[++i + 1] != 0)
	{
		if (i == 0)
		{
			if (!(ft_check_fst_and_lst(qu, i)) || (!ft_player_pos(qu)))
				return (0);
		}
		else
		{
			if (!(ft_pars_str(qu, i)))
				return (ft_error_msg("Error\ninvalid map\n"));
		}
	}
	if (!(ft_check_fst_and_lst(qu, i)))
		return (0);
	if (!(ft_pos_and_dist_sprites(qu)))
		return (0);
	return (ft_wiev_setup(qu));
}

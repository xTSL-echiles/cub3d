/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_parser_p2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:40:41 by echiles           #+#    #+#             */
/*   Updated: 2021/02/09 20:40:43 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_pos_and_dist_sprites(t_options *qu)
{
	int i;
	int x;
	int k;

	i = -1;
	k = -1;
	if (!(qu->sprite = (t_sprite*)malloc(sizeof(t_sprite)
	* (qu->numsprites + 1))))
		return (0);
	while (qu->map[++i])
	{
		x = -1;
		while (qu->map[i][++x])
		{
			if (qu->map[i][x] == '2')
			{
				qu->sprite[++k].sp_x = i + 0.5;
				qu->sprite[k].sp_y = x + 0.5;
			}
		}
	}
	return (1);
}

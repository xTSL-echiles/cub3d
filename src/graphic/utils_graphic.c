/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_graphic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:59:17 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:59:18 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void	quick_sort_2(t_data *img, double *s_arr, int left, int right)
{
	img->sprite_op->tmp = s_arr[left];
	s_arr[left] = s_arr[right];
	s_arr[right] = img->sprite_op->tmp;
	img->sprite_op->sp_xtemp = img->qu->sprite[left].sp_x;
	img->sprite_op->sp_ytemp = img->qu->sprite[left].sp_y;
	img->qu->sprite[left].sp_x = img->qu->sprite[right].sp_x;
	img->qu->sprite[left].sp_y = img->qu->sprite[right].sp_y;
	img->qu->sprite[right].sp_x = img->sprite_op->sp_xtemp;
	img->qu->sprite[right].sp_y = img->sprite_op->sp_ytemp;
}

void	ft_cleaner(t_data *img)
{
	if (img->qu->map)
		ft_cleaner_mass(img->qu->map);
	if (img->qu)
	{
		free(img->qu->sprite);
		free(img->qu);
	}
	if (img->qu->save_flag == 0)
		mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	if (img->all_wall_dist)
		free(img->all_wall_dist);
	free(img);
	exit(1);
}

int		ft_key_close(t_data *img)
{
	ft_cleaner(img);
	return (0);
}

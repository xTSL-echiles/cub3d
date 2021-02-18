/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DDA_setup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:36:41 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 14:36:43 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void	ft_player_pos_again(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->qu->map[i])
	{
		j = 0;
		while (img->qu->map[i][j])
		{
			if (img->qu->map[i][j] == img->qu->player)
			{
				img->pos_plx = (float)i + 0.5;
				img->pos_ply = (float)j + 0.5;
			}
			j++;
		}
		i++;
	}
}

int		ft_init_dda(t_data *img)
{
	ft_player_pos_again(img);
	img->mlx = mlx_init();
	mlx_get_screen_size(img->mlx, &img->img_check_x, &img->img_check_y);
	img->qu->rheig_y = (img->qu->rheig_y < img->img_check_y)
	? img->qu->rheig_y : img->img_check_y;
	img->qu->rwid_x = (img->qu->rwid_x < img->img_check_x)
	? img->qu->rwid_x : img->img_check_x;
	if (img->qu->save_flag == 0)
		img->mlx_win = mlx_new_window(img->mlx,
		img->qu->rwid_x, img->qu->rheig_y, "Cub3D");
	img->dir_x = img->qu->view_x;
	img->dir_y = img->qu->view_y;
	img->plane_x = img->qu->fov_x;
	img->plane_y = img->qu->fov_y;
	img->move_x_down = 0;
	img->move_x_up = 0;
	img->move_y_left = 0;
	img->move_y_right = 0;
	if (!(img->all_wall_dist = (double*)malloc(sizeof(double)
		* (img->qu->rwid_x + 1))))
		return (ft_error_msg("Error\nMalloc error"));
	img->all_wall_dist[img->qu->rwid_x] = '\0';
	ft_texture_set(img);
	return (1);
}

void	ft_dist_for(t_data *img)
{
	if (img->raydir_x < 0)
	{
		img->stepx = -1;
		img->sidedistx = (img->pos_plx - img->mapx) * img->dist_for_x;
	}
	else
	{
		img->stepx = 1;
		img->sidedistx = (img->mapx + 1.0 - img->pos_plx) * img->dist_for_x;
	}
	if (img->raydir_y < 0)
	{
		img->stepy = -1;
		img->sidedisty = (img->pos_ply - img->mapy) * img->dist_for_y;
	}
	else
	{
		img->stepy = 1;
		img->sidedisty = (img->mapy + 1.0 - img->pos_ply) * img->dist_for_y;
	}
}

void	ft_hit(t_data *img)
{
	img->hit = 0;
	while (img->hit == 0)
	{
		if (img->sidedistx < img->sidedisty)
		{
			img->sidedistx += img->dist_for_x;
			img->mapx += img->stepx;
			img->side = 0;
		}
		else
		{
			img->sidedisty += img->dist_for_y;
			img->mapy += img->stepy;
			img->side = 1;
		}
		if (img->qu->map[img->mapx][img->mapy] == '1')
			img->hit = 1;
	}
}

void	ft_raycast_srart(t_data *img)
{
	img->fov_helper = 2 * img->x / (double)img->qu->rwid_x - 1;
	img->raydir_x = img->dir_x + img->plane_x * img->fov_helper;
	img->raydir_y = img->dir_y + img->plane_y * img->fov_helper;
	img->dist_for_x = fabs(1 / img->raydir_x);
	img->dist_for_y = fabs(1 / img->raydir_y);
	img->mapx = (int)img->pos_plx;
	img->mapy = (int)img->pos_ply;
	ft_dist_for(img);
	ft_hit(img);
	if (img->side == 0)
		img->walldist = (img->mapx - img->pos_plx + (1 - img->stepx) / 2)
			/ img->raydir_x;
	else
		img->walldist = (img->mapy - img->pos_ply + (1 - img->stepy) / 2)
			/ img->raydir_y;
}

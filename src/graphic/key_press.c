/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:04:07 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:04:09 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_key_2(int keycode, t_data *img)
{
	if (keycode == 13)
		img->move_x_up = 1;
	else if (keycode == 1)
		img->move_x_down = 1;
	else if (keycode == 123)
		img->move_cam_left = 1;
	else if (keycode == 124)
		img->move_cam_right = 1;
	else if (keycode == 0)
		img->move_y_left = 1;
	else if (keycode == 2)
		img->move_y_right = 1;
	else if (keycode == 53)
		ft_key_close(img);
	return (0);
}

int		ft_key_3(int keycode, t_data *img)
{
	if (keycode == 13)
		img->move_x_up = 0;
	else if (keycode == 1)
		img->move_x_down = 0;
	else if (keycode == 123)
		img->move_cam_left = 0;
	else if (keycode == 124)
		img->move_cam_right = 0;
	else if (keycode == 0)
		img->move_y_left = 0;
	else if (keycode == 2)
		img->move_y_right = 0;
	return (0);
}

int		ft_key_press_p3(t_data *img)
{
	float movespeed;

	movespeed = (img->move_y_left == 1) ? 0.12 : -0.12;
	if ((img->move_y_left == 1 && img->move_y_right != 1) ||
		(img->move_y_right == 1 && img->move_y_left != 1))
	{
		if (img->qu->map[(int)(img->pos_plx - movespeed * img->dir_y)]
		[(int)(img->pos_ply)] != '1' /*&& img->qu->map[(int)(img->pos_plx)]
		[(int)(img->pos_ply + movespeed * img->dir_x)] != '1'*/)
			img->pos_plx -= movespeed * img->dir_y;
		else
			return (0);
		if (img->qu->map[(int)(img->pos_plx)][(int)(img->pos_ply
		+ movespeed * img->dir_x)] != '1' /*&& img->qu->map[(int)(img->pos_plx
		- movespeed * img->dir_y)][(int)(img->pos_ply)] != '1'*/)
			img->pos_ply += movespeed * img->dir_x;
		else
			return (0);
	}
	return (0);
}

int		ft_key_press_p2(t_data *img)
{
	double	old_vec;
	double	angle;
	double	old_vex_plane;

	old_vex_plane = img->plane_x;
	old_vec = img->dir_x;
	angle = (img->move_cam_right == 1) ? -0.1 : 0.1;
	if ((img->move_cam_right == 1 && img->move_cam_left != 1) ||
		(img->move_cam_left == 1 && img->move_cam_right != 1))
	{
		img->dir_x = img->dir_x * cos(angle) - img->dir_y * sin(angle);
		img->dir_y = old_vec * sin(angle) + img->dir_y * cos(angle);
		img->plane_x = img->plane_x * cos(angle) - img->plane_y * sin(angle);
		img->plane_y = old_vex_plane * sin(angle) + img->plane_y * cos(angle);
	}
	return (0);
}

int		ft_key_press(t_data *img)
{
	float	movespeed;

	movespeed = (img->move_x_up == 1) ? 0.1 : -0.1;
	img->img = mlx_new_image(img->mlx, img->qu->rwid_x, img->qu->rheig_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	&img->line_length, &img->endian);
	if ((img->move_x_up == 1 && img->move_x_down != 1) ||
		(img->move_x_down == 1 && img->move_x_up != 1))
	{
		if (img->qu->map[(int)(img->pos_plx + img->dir_x * movespeed)]
		[(int)img->pos_ply] != '1')
			img->pos_plx += img->dir_x * movespeed;
		if (img->qu->map[(int)img->pos_plx][(int)(img->pos_ply
		+ img->dir_y * movespeed)] != '1')
			img->pos_ply += img->dir_y * movespeed;
	}
	ft_key_press_p2(img);
	ft_key_press_p3(img);
	if (!(ft_pirnt_img_to_screen(img)))
		return (ft_error_msg("Malloc error"));
	mlx_destroy_image(img->mlx, img->img);
	return (0);
}

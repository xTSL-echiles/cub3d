/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:39:54 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:39:55 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

int		ft_sprite_dist_sort(t_data *img, int i, int x)
{
	double	sp_xtemp;
	double	sp_ytemp;
	double	disttemp;

	while (++i < img->qu->numsprites)
	{
		x = -1;
		while (++x < img->qu->numsprites)
		{
			if (img->sprite[i].sp_dist > img->sprite[x].sp_dist)
			{
				sp_ytemp = img->sprite[i].sp_y;
				sp_xtemp = img->sprite[i].sp_x;
				disttemp = img->sprite[i].sp_dist;
				img->sprite[i].sp_x = img->sprite[x].sp_x;
				img->sprite[i].sp_y = img->sprite[x].sp_y;
				img->sprite[i].sp_dist = img->sprite[x].sp_dist;
				img->sprite[x].sp_x = sp_xtemp;
				img->sprite[x].sp_y = sp_ytemp;
				img->sprite[x].sp_dist = disttemp;
			}
		}
	}
	return (1);
}

int		ft_pos_and_dist_sprites(t_data *img)
{
	int i;
	int x;
	int k;

	i = -1;
	k = -1;
	if (!(img->sprite = (t_sprite*)malloc(sizeof(t_sprite)
	* (img->qu->numsprites + 1))))
		return (0);
	while (img->qu->map[++i])
	{
		x = -1;
		while (img->qu->map[i][++x])
		{
			if (img->qu->map[i][x] == '2')
			{
				img->sprite[++k].sp_x = i + 0.5;
				img->sprite[k].sp_y = x + 0.5;
				img->sprite[k].sp_dist = (img->pos_plx - img->sprite[k].sp_x)
				* (img->pos_plx - img->sprite[k].sp_x) + (img->pos_ply -
				img->sprite[k].sp_y) * (img->pos_ply - img->sprite[k].sp_y);
			}
		}
	}
	return ((ft_sprite_dist_sort(img, -1, -1)));
}

void	ft_sprite_draw_options(t_data *img, int i)
{
	S_O->spritex = img->sprite[i].sp_x - img->pos_plx;
	S_O->spritey = img->sprite[i].sp_y - img->pos_ply;
	S_O->mod = 1.0 / (img->plane_x * img->dir_y - img->plane_y * img->dir_x);
	S_O->inversex = S_O->mod * (img->dir_y * S_O->spritex -
	img->dir_x * S_O->spritey);
	S_O->inversey = S_O->mod * (-img->plane_y * S_O->spritex
	+ img->plane_x * S_O->spritey);
	S_O->spritewidx = (int)((img->qu->rwid_x / 2) *
	(1 + S_O->inversex / S_O->inversey));
	S_O->spriteheight = abs((int)(img->qu->rheig_y / S_O->inversey));
	S_O->drawstarty = img->qu->rheig_y / 2 - S_O->spriteheight / 2;
	if (S_O->drawstarty < 0)
		S_O->drawstarty = 0;
	S_O->drawendy = S_O->spriteheight / 2 + img->qu->rheig_y / 2;
	if (S_O->drawendy >= img->qu->rheig_y)
		S_O->drawendy = img->qu->rheig_y;
	S_O->spritewidht = abs((int)(img->qu->rheig_y / S_O->inversey));
	S_O->drawstartx = S_O->spritewidx - S_O->spritewidht / 2;
	if (S_O->drawstartx < 0)
		S_O->drawstartx = 0;
	S_O->drawendx = S_O->spritewidht / 2 + S_O->spritewidx;
	if (S_O->drawendx >= img->qu->rwid_x)
		S_O->drawendx = img->qu->rwid_x;
}

void	ft_sprite_printer(t_data *img, int x, int y_cor, int pos)
{
	int y;
	int color_int;

	y = S_O->drawstarty;
	if (S_O->inversey > 0 && x >= 0 && x < img->qu->rwid_x &&
	S_O->inversey < img->all_wall_dist[x])
	{
		while (y < S_O->drawendy)
		{
			y_cor = y * (4 * img->text[4].img_width) - img->qu->rheig_y *
(2 * img->text[4].img_height) + S_O->spriteheight *
(2 * img->text[4].img_height);
			S_O->texy = ((y_cor * (img->text[4].img_height))
			/ S_O->spriteheight) / (4 * img->text[4].img_height);
			pos = (S_O->texy * img->text[4].line_lenght +
				S_O->texx * (img->text[4].bits_per_pixel / 8));
			color_int = *(unsigned int*)(img->text[4].addr + pos);
			if (color_int != IGNORE_C_S)
				ft_my_mlx_printer(img, x, y, color_int);
			y++;
		}
	}
}

int		ft_sprite_init(t_data *img, int y_cor, int pos)
{
	int i;
	int x;

	i = -1;
	if (!(img->sprite_op = (t_sprite_ut*)malloc(sizeof(t_sprite_ut))))
		return (0);
	if (!(ft_pos_and_dist_sprites(img)))
		return (0);
	while (++i < img->qu->numsprites)
	{
		ft_sprite_draw_options(img, i);
		x = S_O->drawstartx - 1;
		while (++x < S_O->drawendx)
		{
			S_O->texx = (int)((4 * img->text[4].img_width) *
			(x - (S_O->spritewidx - S_O->spritewidht / 2))
			* img->text[4].img_width
						/ S_O->spritewidht) / (4 * img->text[4].img_width);
			ft_sprite_printer(img, x, y_cor, pos);
		}
	}
	free(img->sprite);
	free(img->sprite_op);
	return (1);
}

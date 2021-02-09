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

void	quick_sort(t_data *img, double *s_arr, int first, int last)
{
	int		left;
	int		right;
	double	middle;

	if (first < last)
	{
		left = first;
		right = last;
		middle = s_arr[(left + right) / 2];
		while (left <= right)
		{
			while (s_arr[left] < middle)
				left++;
			while (s_arr[right] > middle)
				right--;
			if (left <= right)
			{
				quick_sort_2(img, s_arr, left, right);
				left++;
				right--;
			}
		}
		quick_sort(img, s_arr, first, right);
		quick_sort(img, s_arr, left, last);
	}
}

double	*ft_sprite_dist(t_data *img, double *sprite_dist)
{
	int i;

	i = 0;
	if (!(sprite_dist = (double*)malloc(sizeof(double) *
	(img->qu->numsprites + 1))))
		return (0);
	while (i < img->qu->numsprites)
	{
		sprite_dist[i] = (img->pos_plx - img->qu->sprite[i].sp_x)
		* (img->pos_plx - img->qu->sprite[i].sp_x) + (img->pos_ply -
		img->qu->sprite[i].sp_y) * (img->pos_ply - img->qu->sprite[i].sp_y);
		i++;
	}
	quick_sort(img, sprite_dist, 0, img->qu->numsprites - 1);
	return (sprite_dist);
}

void	ft_sprite_draw_options(t_data *img, int i)
{
	S_O->spritex = img->qu->sprite[i].sp_x - img->pos_plx;
	S_O->spritey = img->qu->sprite[i].sp_y - img->pos_ply;
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
	S_O->inversey < img->all_wall_dist[x] && S_O->inversey > 0.2)
	{
		while (y < S_O->drawendy)
		{
			y_cor = y * 256 - img->qu->rheig_y * (2 * img->text[4].img_height)
			+ S_O->spriteheight * 128;
			S_O->texy = ((y_cor * (img->text[4].img_height))
			/ S_O->spriteheight) / 256;
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
	int		i;
	int		x;
	double	*sprite_dist;

	sprite_dist = NULL;
	i = img->qu->numsprites;
	if (!(img->sprite_op = (t_sprite_ut*)malloc(sizeof(t_sprite_ut))))
		return (0);
	if (!(sprite_dist = ft_sprite_dist(img, sprite_dist)))
		return (0);
	while (--i >= 0)
	{
		ft_sprite_draw_options(img, i);
		x = S_O->drawstartx - 1;
		while (++x < S_O->drawendx)
		{
			S_O->texx = (int)(256 * (x -
			(S_O->spritewidx - S_O->spritewidht / 2))
			* img->text[4].img_width / S_O->spritewidht) / 256;
			ft_sprite_printer(img, x, y_cor, pos);
		}
	}
	free(sprite_dist);
	free(img->sprite_op);
	return (1);
}

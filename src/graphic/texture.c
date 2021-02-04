/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:53:14 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:53:16 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void			ft_my_mlx_printer(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void			ft_texture_set(t_data *img)
{
	img->text[0].img_text = mlx_xpm_file_to_image(img->mlx, img->qu->ea,
	&img->text[0].img_width, &img->text[0].img_height);
	img->text[0].addr = mlx_get_data_addr(img->text[0].img_text,
	&img->text[0].bits_per_pixel, &img->text[0].line_lenght,
	&img->text[0].endian_text);
	img->text[1].img_text = mlx_xpm_file_to_image(img->mlx, img->qu->so,
	&img->text[1].img_width, &img->text[1].img_height);
	img->text[1].addr = mlx_get_data_addr(img->text[1].img_text,
	&img->text[1].bits_per_pixel, &img->text[1].line_lenght,
	&img->text[1].endian_text);
	img->text[2].img_text = mlx_xpm_file_to_image(img->mlx, img->qu->we,
	&img->text[2].img_width, &img->text[2].img_height);
	img->text[2].addr = mlx_get_data_addr(img->text[2].img_text,
	&img->text[2].bits_per_pixel,
	&img->text[2].line_lenght, &img->text[2].endian_text);
	img->text[3].img_text = mlx_xpm_file_to_image(img->mlx, img->qu->no,
	&img->text[3].img_width, &img->text[3].img_height);
	img->text[3].addr = mlx_get_data_addr(img->text[3].img_text,
	&img->text[3].bits_per_pixel,
	&img->text[3].line_lenght, &img->text[3].endian_text);
	img->text[4].img_text = mlx_xpm_file_to_image(img->mlx, img->qu->s,
	&img->text[4].img_width, &img->text[4].img_height);
	img->text[4].addr = mlx_get_data_addr(img->text[4].img_text,
	&img->text[4].bits_per_pixel,
	&img->text[4].line_lenght, &img->text[4].endian_text);
}

unsigned int	ft_get_background_color(t_data *img, char c)
{
	unsigned int rgb;

	if (c == 'f')
		rgb = (img->qu->fr << 16) + (img->qu->fg << 8) + img->qu->fb;
	else
		rgb = (img->qu->cr << 16) + (img->qu->cg << 8) + img->qu->cb;
	return (rgb);
}

int				ft_text_init(t_data *img, int n)
{
	if (img->side == 0 && img->raydir_x < 0)
		n = 3;
	else if (img->side == 0 && img->raydir_x > 0)
		n = 1;
	else if (img->side == 1 && img->raydir_y < 0)
		n = 2;
	if (img->side == 0)
		img->text->wallx = img->pos_ply + img->walldist * img->raydir_y;
	else
		img->text->wallx = img->pos_plx + img->walldist * img->raydir_x;
	img->text->wallx -= floor(img->text->wallx);
	img->text->text_x = (int)(img->text->wallx *
	(double)(img->text[n].img_height));
	if (img->side == 0 && img->raydir_x > 0)
		img->text->text_x = img->text[n].img_height - img->text->text_x - 1;
	if (img->side == 1 && img->raydir_y < 0)
		img->text->text_x = img->text[n].img_height - img->text->text_x - 1;
	return (n);
}

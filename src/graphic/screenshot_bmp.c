/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:24:25 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 16:24:26 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libcub.h"

void	ft_in_1_bite(char *bmp, int size)
{
	bmp[0] = (char)size;
	bmp[1] = (char)(size >> 8);
	bmp[2] = (char)(size >> 16);
	bmp[3] = (char)(size >> 24);
}

void	ft_color(t_data *img, t_bmp *bmp)
{
	int					x;
	int					y;
	unsigned long long	j;

	j = 53;
	y = img->qu->rheig_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < img->qu->rwid_x)
		{
			bmp->screenshot[++j] = img->addr
			[y * img->line_length + x * img->bits_per_pixel / 8];
			bmp->screenshot[++j] = img->addr
			[y * img->line_length + x * img->bits_per_pixel / 8 + 1];
			bmp->screenshot[++j] = img->addr
			[y * img->line_length + x * img->bits_per_pixel / 8 + 2];
			j++;
			x++;
		}
		y--;
	}
}

void	ft_set_header(t_bmp *bmp, t_data *img)
{
	bmp->screenshot[0] = 'B';
	bmp->screenshot[1] = 'M';
	ft_in_1_bite(&bmp->screenshot[2], bmp->size_of_file);
	bmp->screenshot[10] = 54;
	bmp->screenshot[14] = 40;
	ft_in_1_bite(&bmp->screenshot[18], img->qu->rwid_x);
	ft_in_1_bite(&bmp->screenshot[22], img->qu->rheig_y);
	bmp->screenshot[26] = 1;
	bmp->screenshot[28] = 32;
}

int		ft_screen_shot(t_data *img)
{
	t_bmp	*bmp;
	int		fd;

	if (!(bmp = (t_bmp*)malloc(sizeof(t_bmp))))
		return (ft_error_msg("Error\nMalloc error"));
	if ((fd = open("screenshot.bmp", O_CREAT | O_WRONLY, S_IREAD
	| S_IWRITE)) == -1)
		return (ft_error_msg("Error\nCant create|open screenshot"));
	bmp->size_of_file = img->qu->rheig_y * img->qu->rwid_x * 4 + 54;
	if (!(bmp->screenshot = (char*)malloc(sizeof(char) * bmp->size_of_file)))
		return (ft_error_msg("Error\nMalloc error"));
	ft_bzero(bmp->screenshot, bmp->size_of_file);
	ft_set_header(bmp, img);
	ft_color(img, bmp);
	write(fd, bmp->screenshot, bmp->size_of_file);
	free(bmp->screenshot);
	close(fd);
	return (1);
}

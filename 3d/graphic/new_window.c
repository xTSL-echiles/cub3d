#include "../headers/libcub.h"
#include <math.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

static void ft_player_pos(t_data *img)
{
	int i = 0;
	int j = 0;
	while(img->qu->map[i])
	{
		j = 0;
		while(img->qu->map[i][j])
		{
			if(img->qu->map[i][j] == img->qu->player)
			{
				img->pos_plx = (float)i + 0.5;
				img->pos_ply = (float)j + 0.5;
			}
			j++;
		}
		i++;
	}
}
void	ft_init_dda(t_data *img)
{
	ft_player_pos(img);
	img->dir_x = -1; // направление взгляда
	img->dir_y = 0;
	img->plane_x = 0;
	img->plane_y = 0.66; // фов в 66 градусов
	ft_texture_set(img);
}

void	ft_deltadist(t_data *img)
{
	if(img->raydir_x <  0)
	{
		img->stepX = -1;
		img->sidedistX = (img->pos_plx - img->mapX) * img->deltadist_x;
	}
	else
	{
		img->stepX = 1;
		img->sidedistX = (img->mapX + 1.0 - img->pos_plx) * img->deltadist_x;
	}
	if(img->raydir_y < 0)
	{
		img->stepY = -1;
		img->sidedistY = (img->pos_ply - img->mapY) * img->deltadist_y;
	}
	else
	{
		img->stepY = 1;
		img->sidedistY = (img->mapY + 1.0 - img->pos_ply) * img->deltadist_y;
	}
	
}
void	ft_hit(t_data *img)
{
	img->hit = 0;
	while(img->hit == 0)
	{
		if(img->sidedistX < img->sidedistY)
		{
			img->sidedistX += img->deltadist_x;
			img->mapX += img->stepX;
			img->side = 0;
		}
		else
		{
			img->sidedistY += img->deltadist_y;
			img->mapY += img->stepY;
			img->side = 1;
		}
		if(img->qu->map[img->mapX][img->mapY] == '1')
			img->hit = 1;
	}
}

void	ft_raycast_srart(t_data *img)
{
	img->cameraX = 2 * img->x / (double)img->qu->Rwid_x - 1; // Х координата для камера-плейна(линия за игроком)
	img->raydir_x = img->dir_x + img->plane_x * img->cameraX; // 
	img->raydir_y = img->dir_y + img->plane_y * img->cameraX;
	img->deltadist_x = (img->raydir_y == 0) ? 0 : ((img->raydir_x == 0) ? 1 : fabs(1 / img->raydir_x));
    img->deltadist_y = (img->raydir_x == 0) ? 0 : ((img->raydir_y == 0) ? 1 : fabs(1 / img->raydir_y));
	/*img->deltadist_x = sqrt(1 + (img->raydir_y * img->raydir_y)/(img->raydir_x * img->raydir_x));
	img->deltadist_y = sqrt(1 + (img->raydir_x * img->raydir_x)/(img->raydir_y * img->raydir_y));*/
	img->mapX = (int)img->pos_plx;
	img->mapY = (int)img->pos_ply; // где мы на карте (нужно что бы чекать на единичку, как я понял)
	ft_deltadist(img);
	ft_hit(img);
	if(img->side == 0)
		img->walldist = (img->mapX - img->pos_plx + (1 - img->stepX) / 2) / img->raydir_x; // дистанция до стены по Х или У
	else
		img->walldist = (img->mapY - img->pos_ply + (1 - img->stepY) / 2) / img->raydir_y;
}

void	ft_how_to_draw(t_data *img)
{
	img->lineheight = (int)(img->qu->Rheig_y / img->walldist);
	img->drawstart = img->qu->Rheig_y / 2 - img->lineheight / 2;
	if(img->drawstart < 0)
		img->drawstart = 0;
	img->drawend = img->lineheight / 2 + img->qu->Rheig_y / 2; //это как мы делали от старта до енда, только не для фона, а для стен
	if(img->drawend >= img->qu->Rheig_y)
		img->drawend = img->qu->Rheig_y - 1;
}

void	ft_background(t_data *img)
{
	int start;
	int end;
	unsigned int rgb;

	start = img->drawstart;
	end = img->drawend;
	while(start > 0)
	{
		rgb = (ft_get_background_color(img, 'f'));
		my_mlx_pixel_put(img, img->x, start, rgb);
		start--;
	}
	while(img->qu->Rheig_y > end)
	{
		rgb = (ft_get_background_color(img, 'c'));
		my_mlx_pixel_put(img, img->x, end, rgb);
		end++;
	}
}
void	ft_draw(t_data *img)
{
	int	color_int;
	int pos;
	int n;
	double step;
	double texPos;

	n = 0;
	if(img->side == 0 && img->raydir_x < 0)
		n = 3;
	if(img->side == 0 && img->raydir_x > 0)
		n = 1;
	if(img->side == 1 && img->raydir_y < 0)
		n = 2;
	if(img->side == 0)
		img->text->wallx = img->pos_ply + img->walldist * img->raydir_y;
	else
		img->text->wallx = img->pos_plx + img->walldist * img->raydir_x;
	img->text->wallx -= floor(img->text->wallx);
	img->text->text_x = (int)(img->text->wallx * (double)(img->text[n].img_height));
	if(img->side == 0 && img->raydir_x > 0)
		img->text->text_x = img->text[n].img_height - img->text->text_x - 1;
	if(img->side == 1 && img->raydir_y < 0)
		img->text->text_x = img->text[n].img_height - img->text->text_x - 1;
	img->text->text_x = abs(img->text->text_x);
	step = 1.0 * img->text[n].img_height / img->lineheight;
	texPos = (img->drawstart - img->qu->Rheig_y / 2 + img->lineheight / 2) * step;
	while(img->drawstart < img->drawend)
	{
		img->text->text_y = (int)texPos & (img->text[n].img_height - 1);
		texPos += step;
		pos = (img->text->text_y * img->text[n].line_lenght+ img->text->text_x * (img->text[n].bits_per_pixel / 8));
		color_int = *(unsigned int*)(img->text[n].addr + pos);
		my_mlx_pixel_put(img, img->x, img->drawstart, color_int);
		img->drawstart++;
	}
	/*while(img->drawstart < img->drawend)
		{
			img->text->text_y = abs((((img->drawstart * (img->text[n].img_width * 4) - img->qu->Rheig_y *
			(img->text[n].img_height * 2) + img->lineheight * (img->text[n].img_width * 2)) * img->text[n].img_height)
					/ img->lineheight) / (img->text[n].img_height * 4));
			color = &img->text[n].addr[img->text->text_y % img->text[n].img_height * img->text[n].line_lenght +
						img->text->text_x % img->text[n].img_width * img->text[n].bits_per_pixel / 8];
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			my_mlx_pixel_put(img, img->x, img->drawstart, color_int);
			img->drawstart++;
		}*/

}

int		ft_pirnt_img_to_screen(t_data *img)
{
	img->x = 0;
	while(img->x < img->qu->Rwid_x)
	{
		ft_raycast_srart(img);
		ft_how_to_draw(img);
		ft_background(img);
		ft_draw(img);
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return(1);
}
int             main(int argc, char **argv)
{
    t_data  *img;
	if(!(img = (t_data*)malloc(sizeof(t_data))))
	{
		printf("Malloc");
		return(0);
	}
	if(!(ft_parser_start(img, argc, argv)))
	{
		free(img);
		return(0);
	}
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->qu->Rwid_x, img->qu->Rheig_y, "Cyber Punk 2088");
	img->img = mlx_new_image(img->mlx, img->qu->Rwid_x, img->qu->Rheig_y);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                 &img->endian);
	ft_init_dda(img);
	mlx_hook(img->mlx_win, 2, 0, ft_key_press, img);
	ft_pirnt_img_to_screen(img);
	mlx_loop_hook(img->mlx , ft_pirnt_img_to_screen, img);
	mlx_loop(img->mlx);
	return(0);
}
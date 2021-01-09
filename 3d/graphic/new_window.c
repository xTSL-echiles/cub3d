#include "../headers/libcub.h"
#include <math.h>

 //мой говно-код
 /*
void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             hi_there(int keycode, t_data *img)
{
	if(keycode == 2)
		img->player_a+=0.1;
	if(keycode == 1)
	{
		if(img->map[(int)(img->pos_plx - sin(img->player_a))][(int)img->pos_ply] != '1')
			img->pos_plx = img->pos_plx - sin(img->player_a)*0.15;
		if(img->map[(int)img->pos_plx][(int)(img->pos_ply - cos(img->player_a))] != '1')
			img->pos_ply -= cos(img->player_a)*0.15;
	}
	if(keycode == 0)
		img->player_a-=0.1;
	if(keycode == 13)
	{
		if(img->map[(int)(img->pos_plx + sin(img->player_a))][(int)img->pos_ply] != '1')
			img->pos_plx = img->pos_plx + sin(img->player_a)*0.15;
		if(img->map[(int)img->pos_plx][(int)(img->pos_ply + cos(img->player_a))] != '1')
			img->pos_ply += cos(img->player_a)*0.15;
	}
	if(keycode == 53)
		mlx_destroy_window(img->mlx, img->mlx_win);
	return(1);
}

void printer(t_data *img, int end, int start, size_t angle_size, unsigned int rgb)
{
	while(start < end)
	{
		my_mlx_pixel_put(img, angle_size, start, rgb);
		start++;
	}
}

void ft_floor(t_data *img, int end, int start, size_t x)
{
	printer(img, start, 0, x, 0x0075bbfd);
	printer(img, img->qu->Rheig_y, end, x, 0x00f4a460);
}
void cast_luch(t_data *img)
{
	const float fov = 3.14/3;
	double angle;
	float luch_size;
	size_t angle_size;
	angle_size = 0;
	int wall_high = 0;
	int start;
	int end;
	while(angle_size<(size_t)img->qu->Rwid_x)
	{
		angle = img->player_a - fov/2 + fov*angle_size/(float)(img->qu->Rwid_x);
		luch_size = 0;
		while(1)
		{
			
			double cx = img->pos_ply + luch_size*cos(angle);
    	   	double cy = img->pos_plx + luch_size*sin(angle);
			if(img->map[(int)cy][(int)cx] == '1')
				break;
			luch_size += 0.01;
		}
		//wall_high = (img->qu->Rheig/2)/luch_size;
		wall_high = (img->qu->Rheig_y)/(luch_size *cos(angle - img->player_a));
		start = img->qu->Rheig_y/2 - wall_high/2;
		end = start + wall_high;
		if(start < 0)
			start = 0;
		if(end >= img->qu->Rheig_y)
			end = img->qu->Rheig_y - 1;
		ft_floor(img, end, start, angle_size);
		printer(img, end, start, angle_size, 0x0020214F);
		angle_size++;
	}
}

int ft_map_printerr(t_data *img)
{
	int i = 0;
	int j = 0;
	while(img->map[i])
	{
		j = 0;
		while(img->map[i][j])
		{
			if(img->map[i][j] == img->qu->player && img->find_position == 0)
			{
				img->find_position = 1;
				img->pos_plx = i;
				img->pos_ply = j;
			}
			j++;
		}
		i++;
	}
	cast_luch(img);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return(1);

}*/


// DDA алгоритм

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
	while(img->map[i])
	{
		j = 0;
		while(img->map[i][j])
		{
			if(img->map[i][j] == img->qu->player)
			{
				img->pos_plx = i;
				img->pos_ply = j;
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
		if(img->map[img->mapX][img->mapY] == '1')
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
	/*img->deltadist_x = sqrt(1 + (img->raydir_y * img->raydir_y)/
						(img->raydir_x * img->raydir_x));
	img->deltadist_y = sqrt(1 + (img->raydir_x * img->raydir_x) /
						(img->raydir_y * img->raydir_y)); */
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
	int start = img->qu->Rheig_y/2 - img->lineheight/2;
	int end = img->drawend;
	while(start > 0)
	{
		my_mlx_pixel_put(img, img->x, start, 0x0075bbfd);
		start--;
	}
	while(img->qu->Rheig_y > end)
	{
		my_mlx_pixel_put(img, img->x, end, 0x00f4a460);
		end++;
	}
}
void	ft_draw(t_data *img)
{
	if(img->side == 0)
		img->text->wallx = img->pos_ply + img->walldist * img->dir_y;
	else
		img->text->wallx = img->pos_plx + img->walldist * img->raydir_x;
	img->text->text_x = (int)(img->text->wallx * (double)(64));
	if(img->side == 0 && img->raydir_x > 0)
		img->text->text_x = 64 - img->text->text_x - 1;
	if(img->side == 1 && img->raydir_y < 0)
		img->text->text_x = 64 - img->text->text_x - 1;
	while(img->drawstart <= img->drawend)
		{
			my_mlx_pixel_put(img, img->x, img->drawstart, img->RGB);
			img->drawstart++;
		}
}
int		ft_pirnt_img_to_screen(t_data *img)
{
	img->x = 0;
	while(img->x < img->qu->Rwid_x)
	{
		ft_raycast_srart(img);
		ft_how_to_draw(img);
		img->RGB = 0x808080;
		ft_background(img);
		ft_draw(img);
		img->x++;
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return(1);
}
int             main(int argc, char **argv)
{
    t_data  *img;

	img = (t_data*)malloc(sizeof(t_data));
	if(!(ft_parser_start(img, argc, argv)))
		return(0);
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

/*
int             main(int argc, char **argv)
{
    t_data  *img;

	img = (t_data*)malloc(sizeof(t_data));
	if(!(ft_parser_start(img, argc, argv)))
		return(0);
	img->player_a = 0;
	img->find_position = 0;
   	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, img->qu->Rwid_x, img->qu->Rheig_y, "Hello world!");
	

	img->img = mlx_new_image(img->mlx, img->qu->Rwid_x, img->qu->Rheig_y);
    img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
                                 &img->endian);
	mlx_hook(img->mlx_win, 2, 0, hi_there, img);
	mlx_loop_hook(img->mlx , ft_map_printerr, img);
	mlx_loop(img->mlx);
	return(0);
}*/
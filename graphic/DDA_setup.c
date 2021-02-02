#include "../headers/libcub.h"

static void	ft_player_pos(t_data *img)
{
	int i;
	int j;

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
	ft_player_pos(img);
	img->dir_x = img->qu->view_x; // направление взгляда
	img->dir_y = img->qu->view_y;
	img->plane_x = img->qu->fov_x;
	img->plane_y = img->qu->fov_y; // фов в 66 градусов
	img->move_x_down = 0;
	img->move_x_up = 0;
	img->move_y_left = 0;
	img->move_y_right = 0;
	if (!(img->all_wall_dist = (double*)malloc(sizeof(double) * (img->qu->Rwid_x + 1))))
		return (ft_error_msg("Malloc error"));
	img->all_wall_dist[img->qu->Rwid_x] = '\0';
	ft_texture_set(img);
	return(1);
}

void	ft_deltadist(t_data *img)
{
	/*вычисляем координаты луча в зависимости от направления взгляда, тут мы находим дистанцию до пересечения клетки\пикселя в
	первый раз, т.е. к изначальной позиции (игрока) прибавляем дельту*/
	if (img->raydir_x <  0)
	{
		img->stepX = -1;
		img->sidedistX = (img->pos_plx - img->mapX) * img->deltadist_x;
	}
	else
	{
		img->stepX = 1;
		img->sidedistX = (img->mapX + 1.0 - img->pos_plx) * img->deltadist_x;
	}
	if (img->raydir_y < 0)
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
	while (img->hit == 0)
	{
		if (img->sidedistX < img->sidedistY)
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
		if (img->qu->map[img->mapX][img->mapY] == '1')
			img->hit = 1;
	}
}

void	ft_raycast_srart(t_data *img)
{
	img->cameraX = 2 * img->x / (double)img->qu->Rwid_x - 1; // Х координата для камера-плейна(линия за игроком), помогает отрисовать ФОВ, принимает значения от -1 до 1
	img->raydir_x = img->dir_x + img->plane_x * img->cameraX; /*точка по У  конечного направление взгляда, например, 
	мы задаем ее в ручную (-1) */
	img->raydir_y = img->dir_y + img->plane_y * img->cameraX; /* допустим, 0.66 * -1, точка по Х конечного направления
	взгляда умноженая на ФОВ-помошника, позволяет определить положение конечной точки по X (по ладеву по игрику) */
	
	img->deltadist_x = (img->raydir_y == 0) ? 0 : ((img->raydir_x == 0) ? 1 : fabs(1 / img->raydir_x));
    img->deltadist_y = (img->raydir_x == 0) ? 0 : ((img->raydir_y == 0) ? 1 : fabs(1 / img->raydir_y)); // сколько и где пройдет луч за 1 клетку
	//printf("dirX= %f dirY= %f deltaY= %f deltaX= %f\n", img->raydir_x, img->raydir_y, img->deltadist_y, img->deltadist_x);
	/*img->deltadist_x = sqrt(1 + (img->raydir_y * img->raydir_y)/(img->raydir_x * img->raydir_x));
	img->deltadist_y = sqrt(1 + (img->raydir_x * img->raydir_x)/(img->raydir_y * img->raydir_y));*/
	img->mapX = (int)img->pos_plx;
	img->mapY = (int)img->pos_ply; // где мы на карте (нужно что бы чекать на единичку, как я понял)
	ft_deltadist(img);
	ft_hit(img);
	if (img->side == 0)
		img->walldist = (img->mapX - img->pos_plx + (1 - img->stepX) / 2) / img->raydir_x; // дистанция до стены по Х или У
	else
		img->walldist = (img->mapY - img->pos_ply + (1 - img->stepY) / 2) / img->raydir_y;
}
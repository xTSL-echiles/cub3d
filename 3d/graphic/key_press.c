#include "../headers/libcub.h"
void	ft_key_press_p2(int keycode, t_data *img)
{
	double oldDirX;
	float rotSpeed;
	double oldPlaneX;

	oldPlaneX = img->plane_x;
	oldDirX = img->dir_x;
	rotSpeed = 0.15;
	if(keycode == 2)
    {
      img->dir_x = img->dir_x * cos(-rotSpeed) - img->dir_y * sin(-rotSpeed);
      img->dir_y = oldDirX * sin(-rotSpeed) + img->dir_y * cos(-rotSpeed);
      img->plane_x = img->plane_x * cos(-rotSpeed) - img->plane_y * sin(-rotSpeed);
      img->plane_y = oldPlaneX * sin(-rotSpeed) + img->plane_y * cos(-rotSpeed);
	}
	if(keycode == 0)
    {
      img->dir_x = img->dir_x * cos(rotSpeed) - img->dir_y * sin(rotSpeed);
      img->dir_y = oldDirX * sin(rotSpeed) + img->dir_y * cos(rotSpeed);
      img->plane_x = img->plane_x * cos(rotSpeed) - img->plane_y * sin(rotSpeed);
      img->plane_y = oldPlaneX * sin(rotSpeed) + img->plane_y * cos(rotSpeed);
    }
}

int	ft_key_press(int keycode, t_data *img)
{
	float movespeed;

	movespeed = 0.5;
	if (keycode == 53)
		exit(1);
	if(keycode == 13)
	{	
		if(img->map[(int)(img->pos_plx + img->dir_x * movespeed)][(int)img->pos_ply] != '1')
			img->pos_plx += img->dir_x * movespeed;
		if(img->map[(int)img->pos_plx][(int)(img->pos_ply + img->dir_y * movespeed)] != '1')
			img->pos_ply += img->dir_y * movespeed;
	}
	else if(keycode == 1)
	{	
		if(img->map[(int)(img->pos_plx - img->dir_x * movespeed)][(int)img->pos_ply] != '1')
			img->pos_plx -= img->dir_x * movespeed;
		if(img->map[(int)img->pos_plx][(int)(img->pos_ply - img->dir_y * movespeed)] != '1')
			img->pos_ply -= img->dir_y * movespeed;
	}
	else 
		ft_key_press_p2(keycode, img);
	return(0);
}

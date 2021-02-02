#include "../headers/libcub.h"


void	ft_how_to_draw(t_data *img)
{
	img->lineheight = (int)(img->qu->Rheig_y / img->walldist);
	img->drawstart = img->qu->Rheig_y / 2 - img->lineheight / 2;
	if(img->drawstart < 0)
		img->drawstart = 0;
	img->drawend = img->lineheight / 2 + img->qu->Rheig_y / 2; //это как мы делали от старта до енда, только не для фона, а для стен
	if(img->drawend >= img->qu->Rheig_y)
		img->drawend = img->qu->Rheig_y;
}

void	ft_background(t_data *img)
{
	int start;
	int end;
	unsigned int rgb;

	start = img->drawstart;
	end = img->drawend;
	while(start >= 0)
	{
		rgb = (ft_get_background_color(img, 'f'));
		ft_my_mlx_printer(img, img->x, start, rgb);
		start--;
	}
	while(img->qu->Rheig_y > end)
	{
		rgb = (ft_get_background_color(img, 'c'));
		ft_my_mlx_printer(img, img->x, end, rgb);
		end++;
	}
}
void	ft_draw_wall(t_data *img)
{
	unsigned int	color_int;
	int pos;
	int n;
	double step;

	n = 0;
	n = ft_text_init(img, n);
	step = (double)img->text[n].img_height / img->lineheight;
	while(img->drawstart < img->drawend)
	{
		img->text->text_y = (int)((img->drawstart - img->qu->Rheig_y / 2 + img->lineheight / 2) * step);
		pos = (img->text->text_y * img->text[n].line_lenght + img->text->text_x * (img->text[n].bits_per_pixel / 8));
		// Uint32 color = texture[texNum][texHeight * texY + texX]; поменять на ширину;
		color_int = *(unsigned int*)(img->text[n].addr + pos);
		ft_my_mlx_printer(img, img->x, img->drawstart, color_int);
		img->text->text_y += step;
		img->drawstart++;
	}
	img->all_wall_dist[img->x] = img->walldist;
	//printf("x[%d]%f\n", img->x, img->zBuffer[img->x]);
	/*while(img->drawstart < img->drawend)
		{
			img->text->text_y = abs((((img->drawstart * (img->text[n].img_width * 4) - img->qu->Rheig_y *
			(img->text[n].img_height * 2) + img->lineheight * (img->text[n].img_width * 2)) * img->text[n].img_height)
					/ img->lineheight) / (img->text[n].img_height * 4));
			color = &img->text[n].addr[img->text->text_y % img->text[n].img_height * img->text[n].line_lenght +
						img->text->text_x % img->text[n].img_width * img->text[n].bits_per_pixel / 8];
			color_int = ((unsigned char)color[2] << 16) + ((unsigned char)color[1] << 8) + (unsigned char)color[0];
			ft_my_mlx_printer(img, img->x, img->drawstart, color_int);
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
		ft_draw_wall(img);
		img->x++;
	}
	if(!(ft_sprite_init(img, 0, 0, 0)))
				return(ft_error_msg("Malloc error"));
	if(img->qu->save_flag == 1)
	{
		ft_screen_shot(img);
		ft_cleaner(img);
	}
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	mlx_do_sync(img->mlx);
	return(1);
}

int             main(int argc, char **argv)
{
	t_data  *img;
	if(!(img = (t_data*)malloc(sizeof(t_data))))
		return(ft_error_msg("Malloc error"));
	if(!(ft_parser_start(img, argc, argv)))
	{
		free(img);
		return(0);
	}
	img->mlx = mlx_init();
	mlx_get_screen_size(img->mlx, &img->img_check_x, &img->img_check_y);
	img->qu->Rheig_y = (img->qu->Rheig_y < img->img_check_y) ? img->qu->Rheig_y : img->img_check_y;
	img->qu->Rwid_x = (img->qu->Rwid_x < img->img_check_x) ? img->qu->Rwid_x : img->img_check_x;
	if(img->qu->save_flag == 0)
		img->mlx_win = mlx_new_window(img->mlx, img->qu->Rwid_x, img->qu->Rheig_y, "Cub3D");
	if(!(ft_init_dda(img)))
		return(0);
	if(img->qu->save_flag == 1)
		ft_key_press(img);
	mlx_hook(img->mlx_win, 2, 0, ft_key_2, img);
	mlx_hook(img->mlx_win, 3, 0, ft_key_3, img);
	mlx_hook(img->mlx_win, 17, 0, ft_key_close, img);
	mlx_loop_hook(img->mlx , ft_key_press, img);
	mlx_loop(img->mlx);
	return(0);
}
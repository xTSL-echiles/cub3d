#include "../headers/libcub.h"

int		ft_sprite_dist_sort(t_data *img,int i, int x)
{
	double posxtemp;
	double posytemp;
	double disttemp;

	while(++i < img->qu->numSprites)
	{
		x = -1;
		while(++x < img->qu->numSprites)
		{
			if(img->sprite[i].spriteDist > img->sprite[x].spriteDist)
			{
				posytemp = img->sprite[i].posY;
				posxtemp = img->sprite[i].posX;
				disttemp = img->sprite[i].spriteDist;
				img->sprite[i].posX = img->sprite[x].posX;
				img->sprite[i].posY = img->sprite[x].posY;
				img->sprite[i].spriteDist = img->sprite[x].spriteDist;
				img->sprite[x].posX = posxtemp;
				img->sprite[x].posY = posytemp;
				img->sprite[x].spriteDist = disttemp;
			}
		}
	}
	return(1);
}

int		ft_pos_and_dist_sprites(t_data *img)
{
	int i;
	int x;
	int k;

	i = -1;
	k = -1;
	if(!(img->sprite = (t_sprite*)malloc(sizeof(t_sprite) * (img->qu->numSprites + 1))))
		return(0);
	while(img->qu->map[++i])
	{
		x = -1;
		while(img->qu->map[i][++x])
		{
			if(img->qu->map[i][x] == '2')
			{
				k++;
				img->sprite[k].posX = i + 0.5;
				img->sprite[k].posY = x + 0.5;
				img->sprite[k].spriteDist = (img->pos_plx - img->sprite[k].posX) * (img->pos_plx - img->sprite[k].posX) +
				(img->pos_ply - img->sprite[k].posY) * (img->pos_ply - img->sprite[k].posY);
			}
		}
	}
	return((ft_sprite_dist_sort(img, -1, -1)));
}
void	ft_sprite_draw_options(t_data *img, int i)
{
	S_O->spriteX = img->sprite[i].posX - img->pos_plx;
	S_O->spriteY = img->sprite[i].posY - img->pos_ply;
	S_O->invDet = 1.0 / (img->plane_x * img->dir_y - img->plane_y * img->dir_x);
	S_O->transformX = S_O->invDet * (img->dir_y * S_O->spriteX - img->dir_x * S_O->spriteY);
	S_O->transformY = S_O->invDet * (-img->plane_y * S_O->spriteX + img->plane_x * S_O->spriteY); //это местоположение спрайта в зависимости от вязгяда игрока (если сзади 0:-1, спереди 0:1)
	S_O->spritescreenX = (int)((img->qu->Rwid_x / 2) * (1 + S_O->transformX / S_O->transformY));
	S_O->spriteHeight = abs((int)(img->qu->Rheig_y / S_O->transformY));
	S_O->drawstartY = img->qu->Rheig_y / 2 - S_O->spriteHeight / 2 ;
	if(S_O->drawstartY < 0)
		S_O->drawstartY = 0;
	S_O->drawendY = S_O->spriteHeight / 2 + img->qu->Rheig_y / 2;
	if(S_O->drawendY >= img->qu->Rheig_y)
		S_O->drawendY = img->qu->Rheig_y;
	S_O->spriteWidht = abs((int)(img->qu->Rheig_y / S_O->transformY));
	S_O->drawstartX =  S_O->spritescreenX - S_O->spriteWidht / 2;
	if(S_O->drawstartX < 0)
		S_O->drawstartX = 0;
	S_O->drawendX = S_O->spriteWidht / 2 + S_O->spritescreenX;
	if(S_O->drawendX >= img->qu->Rwid_x)
		S_O->drawendX = img->qu->Rwid_x;
}

void	ft_sprite_printer(t_data *img, int x, int y_cor, int pos, int color_int)
{
	int y;
	(void)y_cor;
	y = S_O->drawstartY;
	double step = (double)img->text[4].img_height / S_O->spriteHeight;
	if(S_O->transformY > 0 && x >= 0 && x < img->qu->Rwid_x && S_O->transformY < img->all_wall_dist[x])
	{
		while(y < S_O->drawendY){
		S_O->texY = (int)((S_O->drawstartY - img->lineheight / 2 + S_O->spriteHeight / 2) * step);
		pos = S_O->texY * img->text[4].line_lenght + x * (img->text[4].bits_per_pixel / 8);
		color_int = *(unsigned int*)(img->text[4].addr + pos);
		ft_my_mlx_printer(img, x, y, color_int);
		y++;}
/*		while(y < S_O->drawendY)
		{
			y_cor = y * (4*img->text[4].img_width) - img->qu->Rheig_y * (2*img->text[4].img_height) + S_O->spriteHeight * (2*img->text[4].img_height);
			S_O->texY = ((y_cor * (img->text[4].img_height)) / S_O->spriteHeight) / (4*img->text[4].img_height);
			pos = (S_O->texY * img->text[4].line_lenght + S_O->texX * (img->text[4].bits_per_pixel / 8));
			color_int = *(unsigned int*)(img->text[4].addr + pos);
			if(color_int != IGNORE_C_S)
				ft_my_mlx_printer(img, x, y, color_int);
			y++;
		}*/
	}	/*while(img->drawstart < img->drawend)
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

int		ft_sprite_init(t_data *img, int y_cor, int pos, int color_int)
{
	int i;
	int x;

	i = -1;
	if(!(img->sprite_op = (t_sprite_ut*)malloc(sizeof(t_sprite_ut))))
		return(0);
	if(!(ft_pos_and_dist_sprites(img)))
		return(0);
	while(++i < img->qu->numSprites)
	{
		ft_sprite_draw_options(img, i);
		x = S_O->drawstartX - 1;
		while(++x < S_O->drawendX)
		{
			S_O->texX = (int)((4*img->text[4].img_width) * (x - (S_O->spritescreenX -
				S_O->spriteWidht / 2 )) * img->text[4].img_width
						/ S_O->spriteWidht) / (4*img->text[4].img_width);
			ft_sprite_printer(img, x, y_cor, pos, color_int);
		}
	}
	free(img->sprite);
	free(img->sprite_op);
	return(1);
}
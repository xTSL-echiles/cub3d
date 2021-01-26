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
	img->sprite_op->spriteX = img->sprite[i].posX - img->pos_plx;
	img->sprite_op->spriteY = img->sprite[i].posY - img->pos_ply;
	img->sprite_op->invDet = 1.0 / (img->plane_x * img->dir_y - img->plane_y * img->dir_x);
	img->sprite_op->transformX = img->sprite_op->invDet * (img->dir_y * img->sprite_op->spriteX - img->dir_x * img->sprite_op->spriteY);
	img->sprite_op->transformY = img->sprite_op->invDet * (-img->plane_y * img->sprite_op->spriteX + img->plane_x * img->sprite_op->spriteY); //это местоположение спрайта в зависимости от вязгяда игрока (если сзади 0:-1, спереди 0:1)
	img->sprite_op->spritescreenX = (int)((img->qu->Rwid_x / 2) * (1 + img->sprite_op->transformX / img->sprite_op->transformY));
	img->sprite_op->spriteHeight = abs((int)(img->qu->Rheig_y / img->sprite_op->transformY));
	img->sprite_op->drawstartY = img->qu->Rheig_y / 2 - img->sprite_op->spriteHeight / 2 ;
	if(img->sprite_op->drawstartY < 0)
		img->sprite_op->drawstartY = 0;
	img->sprite_op->drawendY = img->sprite_op->spriteHeight / 2 + img->qu->Rheig_y / 2;
	if(img->sprite_op->drawendY >= img->qu->Rheig_y)
		img->sprite_op->drawendY = img->qu->Rheig_y;
	img->sprite_op->spriteWidht = abs((int)(img->qu->Rheig_y / img->sprite_op->transformY));
	img->sprite_op->drawstartX =  img->sprite_op->spritescreenX - img->sprite_op->spriteWidht / 2;
	if(img->sprite_op->drawstartX < 0)
		img->sprite_op->drawstartX = 0;
	img->sprite_op->drawendX = img->sprite_op->spriteWidht / 2 + img->sprite_op->spritescreenX;
	if(img->sprite_op->drawendX >= img->qu->Rwid_x)
		img->sprite_op->drawendX = img->qu->Rwid_x;
}

void	ft_sprite_printer(t_data *img, int x, int y_cor, int pos, unsigned int color_int)
{
	int y;

	y = img->sprite_op->drawstartY;
	if(img->sprite_op->transformY > 0 && x >= 0 && x < img->qu->Rwid_x && img->sprite_op->transformY < img->zBuffer[x])
	{
		while(y < img->sprite_op->drawendY)
		{
			y_cor = y * (4*img->text[4].img_width) - img->qu->Rheig_y * (2*img->text[4].img_height) + img->sprite_op->spriteHeight * (2*img->text[4].img_height);
			img->sprite_op->texY = ((y_cor * (img->text[4].img_height)) / img->sprite_op->spriteHeight) / (4*img->text[4].img_height);
			if(img->sprite_op->texY < 0)
				img->sprite_op->texY = 0;
			if(img->sprite_op->texY > img->text[4].img_width)
				img->sprite_op->texY = img->text[4].img_width;
			pos = (img->sprite_op->texY * img->text[4].line_lenght + img->sprite_op->texX * (img->text[4].bits_per_pixel / 8));
			color_int = *(unsigned int*)(img->text[4].addr + pos);
			if(color_int != 0x000000)
				ft_my_mlx_printer(img, x, y, color_int);
			y++;
		}
	}
}

int		ft_sprite_init(t_data *img, int y_cor, int pos, unsigned int color_int)
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
		x = img->sprite_op->drawstartX - 1;
		while(++x < img->sprite_op->drawendX)
		{
			img->sprite_op->texX = (int)((4*img->text[4].img_width) * (x - (img->sprite_op->spritescreenX -
				img->sprite_op->spriteWidht / 2 )) * img->text[4].img_width
						/ img->sprite_op->spriteWidht) / (4*img->text[4].img_width);
			ft_sprite_printer(img, x, y_cor, pos, color_int);
		}
	}
	return(1);
}
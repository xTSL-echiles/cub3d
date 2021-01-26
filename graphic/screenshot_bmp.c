#include "../headers/libcub.h"

void	ft_in_1_bite(char *bmp, int size)
{
	bmp[0] = (char)size;
	bmp[1] = (char)(size >> 8);
	bmp[2] = (char)(size >> 16);
	bmp[4] = (char)(size >> 24);
}

void		ft_color(t_data *img, int fd)
{
	int x;
	int y;

	y = img->qu->Rheig_y;
	while(y >= 0)
	{
		x = 0;
		while(x < img->qu->Rwid_x)
		{	
			write(fd, &img->addr[y * img->line_length + x * img->bits_per_pixel / 8], 1);
			write(fd, &img->addr[y * img->line_length + x * img->bits_per_pixel / 8 + 1], 1);
			write(fd, &img->addr[y * img->line_length + x * img->bits_per_pixel / 8 + 2], 1);
			write(fd, 0, 1);
			x++;
		}
		y--;
	}
}

void	ft_set_header(t_bmp *bmp, t_data *img, int fd)
{
	bmp->screenshot[0] = 'B';
	bmp->screenshot[1] = 'M';
	ft_in_1_bite(&bmp->screenshot[2], bmp->size_of_file);
	bmp->screenshot[10] = 54;
	bmp->screenshot[14] = 40;
	ft_in_1_bite(&bmp->screenshot[18], img->qu->Rwid_x);
	ft_in_1_bite(&bmp->screenshot[22], img->qu->Rheig_y);
	bmp->screenshot[26] = 1;
	bmp->screenshot[28] = 24;
	write(fd, bmp->screenshot, 54);
}

int	ft_screen_shot(t_data *img)
{
	t_bmp *bmp;
	int fd;

	if(!(bmp = (t_bmp*)malloc(sizeof(t_bmp))))
		return(ft_error_msg("Malloc error"));
	fd = open("ETO_SCREEN.bmp", O_CREAT|O_WRONLY, S_IREAD|S_IWRITE);
	bmp->size_of_file = img->qu->Rheig_y * img->qu->Rwid_x * 3 + 54;
	if(!(bmp->screenshot = (char*)malloc(sizeof(char) * 54)))
		return(ft_error_msg("Malloc error"));
	ft_bzero(bmp->screenshot, 54);
	ft_set_header(bmp, img, fd);
	ft_color(img, fd);
	close(fd);
	return(1);
}
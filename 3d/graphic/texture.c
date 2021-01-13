#include "../headers/libcub.h"

void	ft_texture_set(t_data *img)
{
	/*(void)img;
	text->mlx_text = mlx_init();
	text->img_text = mlx_xpm_file_to_image(text->mlx_text, "texture/redbrick.xpm", &text->img_width, &text->img_height);
	text->addr = mlx_get_data_addr(text->img_text, &text->bits_per_pixel,
	&text->line_lenght, &text->endian_text);*/
	img->text->mlx_text = mlx_init();
	img->text[0].img_text = mlx_xpm_file_to_image(img->text->mlx_text, "texture/Hittler.xpm", &img->text[0].img_width, &img->text[0].img_height);
	img->text[0].addr = mlx_get_data_addr(img->text[0].img_text, &img->text[0].bits_per_pixel,
	&img->text[0].line_lenght, &img->text[0].endian_text);
	img->text[1].img_text = mlx_xpm_file_to_image(img->text->mlx_text, "texture/WALL34.xpm", &img->text[1].img_width, &img->text[1].img_height);
	img->text[1].addr = mlx_get_data_addr(img->text[1].img_text, &img->text[1].bits_per_pixel,
	&img->text[1].line_lenght, &img->text[1].endian_text);
	img->text[2].img_text = mlx_xpm_file_to_image(img->text->mlx_text, "texture/redbrick.xpm", &img->text[2].img_width, &img->text[2].img_height);
	img->text[2].addr = mlx_get_data_addr(img->text[2].img_text, &img->text[2].bits_per_pixel,
	&img->text[2].line_lenght, &img->text[2].endian_text);
	img->text[3].img_text = mlx_xpm_file_to_image(img->text->mlx_text, "texture/hell_pent01.xpm", &img->text[3].img_width, &img->text[3].img_height);
	img->text[3].addr = mlx_get_data_addr(img->text[3].img_text, &img->text[3].bits_per_pixel,
	&img->text[3].line_lenght, &img->text[3].endian_text);
}

unsigned int	ft_get_background_color(t_data *img, char c)
{
	unsigned int rgb;

	if(c == 'f')
		rgb = (img->qu->fr << 16) + (img->qu->fg << 8) + img->qu->fb;
	else
		rgb = (img->qu->cr << 16) + (img->qu->cg << 8) + img->qu->cb;
	return(rgb);
}
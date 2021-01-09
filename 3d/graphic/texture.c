#include "libcub.h"
void	texture_setup(t_data *img)
{
	int a;
	int b;

	a = 64;
	b = 64;
	img->text[1].img_text = mlx_xpm_file_to_image(img->mlx, "texture/wood.xpm", &a, &b);
	img->text[1].data_text = mlx_get_data_addr(img->text[1].img_text, &img->text[1].bit_p_p_text,
	&img->text[1].line_lenght_text, &img->text[1].endian_text);
}
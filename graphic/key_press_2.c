#include "../headers/libcub.h"
void	ft_cleaner(t_data *img)
{
	ft_cleaner_mass(img->qu->map);
	free(img->qu);
	if(img->qu->save_flag == 0)
		mlx_destroy_window(img->mlx, img->mlx_win);
	free(img->mlx);
	free(img);
	exit(1);
}

int		ft_key_close(t_data *img)
{
	ft_cleaner(img);
	return(0);
}
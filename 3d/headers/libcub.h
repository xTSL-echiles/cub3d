#ifndef LIBCUB_H
# define LIBCUB_H
#include "get_next_line.h"
#include "../minilibx_opengl_20191021/mlx.h"

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <math.h>

typedef struct 			s_options
{
	int 		Rwid_x;
	int 		Rheig_y;
	char		*no;
	char 		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			fr;
	int			fg;
	int			fb;
	int			cr;
	int			cg;
	int			cb;
	int			acces;
	char		**map;
	char		player;
	char		*filename;
}						t_options;


typedef	struct			s_text					
{
	void		*img_text;
	char		*addr;
	int			bits_per_pixel;
	int			line_lenght;
	int			endian_text;
	int			text_x;
	int			text_y;
	double		wallx;
	void		*mlx_text;
	int			img_width;
    int			img_height;
}						t_text;


typedef struct			s_data 
{
	// mlx options
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	void    	*mlx;
    void   		*mlx_win;
	float 		player_a;
	t_options	*qu;
	//dda options
	double 		pos_plx;
	double 		pos_ply;
	double		cameraX;
	double		raydir_x;
	double		raydir_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			x;
	double		deltadist_x;
	double		deltadist_y;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	double		sidedistX;
    double		sidedistY;
	int			hit;
	int			side;
	double		walldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			RGB;
	// для текстур
	t_text		text[5];
}						t_data;



int				ft_atoi(const char *nptr);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
void			*ft_calloc(size_t count, size_t size);
void			*ft_bzero(void *s, size_t n);
char			*ft_strcpy(char *src);
int				ft_isdigit(int c);
void			ft_putstr_fd(char *s);
int				ft_acces_checker(t_options *qu);
void			ft_all_null_now(t_options *qu);
void 			pars_check(t_options *qu, char *line);
void			ft_cleaner_mass(char **ans);
int				ft_parser_map(t_options *qu);
int				ft_cptain_prise(t_options *qu);
int				ft_check_digit_in_colors(char **ans);
int 			ft_check_save(char *save);
int				ft_check_file_name(t_options *qu);
int 			ft_check_0_line_in_map(char *save, char *line);
int				ft_map_printer(t_options *qu);
int 			ft_check_argv(t_options *qu, char **argv, int argc);
int 			ft_parser_start(t_data *img, int ar, char **arg);
int				ft_key_press(int keycode, t_data * img);
int				ft_pirnt_img_to_screen(t_data *img);
void			ft_texture_set(t_data *img);
unsigned int	ft_get_background_color(t_data *img, char c);
int				ft_error_msg(char *s);
#endif
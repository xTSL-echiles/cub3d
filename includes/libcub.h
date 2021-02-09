/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echiles <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 18:02:09 by echiles           #+#    #+#             */
/*   Updated: 2021/02/02 18:02:10 by echiles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBCUB_H
# define LIBCUB_H

# include "get_next_line.h"
# include "../minilibx_mms_20200219/mlx.h"

# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <math.h>

# define IGNORE_C_S	0x000000
# define S_O		img->sprite_op

typedef	struct			s_sprites
{
	double				sp_x;
	double				sp_y;
}						t_sprite;

typedef struct			s_options
{
	int					rwid_x;
	int					rheig_y;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int					fr;
	int					fg;
	int					fb;
	int					cr;
	int					cg;
	int					cb;
	int					acces;
	char				**map;
	char				player;
	char				*filename;
	double				view_x;
	double				view_y;
	double				fov_x;
	double				fov_y;
	int					numsprites;
	int					save_flag;
	t_sprite			*sprite;

}						t_options;

typedef	struct			s_text
{
	void				*img_text;
	char				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian_text;
	int					text_x;
	int					text_y;
	double				wallx;
	int					img_width;
	int					img_height;
}						t_text;

typedef	struct			s_sprites_ut
{
	double				spritex;
	double				spritey;
	double				mod;
	double				inversex;
	double				inversey;
	int					spritewidx;
	int					spriteheight;
	int					drawstarty;
	int					drawendy;
	int					spritewidht;
	int					drawstartx;
	int					drawendx;
	int					texx;
	int					texy;
}						t_sprite_ut;

typedef struct			s_data
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	void				*mlx;
	void				*mlx_win;
	int					img_check_x;
	int					img_check_y;
	double				pos_plx;
	double				pos_ply;
	double				fov_helper;
	double				raydir_x;
	double				raydir_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	int					x;
	double				dist_for_x;
	double				dist_for_y;
	int					mapx;
	int					mapy;
	int					stepx;
	int					stepy;
	double				sidedistx;
	double				sidedisty;
	int					hit;
	int					side;
	double				walldist;
	int					lineheight;
	int					drawstart;
	int					drawend;
	double				*all_wall_dist;
	t_text				text[5];
	t_options			*qu;
	t_sprite_ut			*sprite_op;
	int					move_x_up;
	int					move_x_down;
	int					move_y_right;
	int					move_y_left;
	int					move_cam_right;
	int					move_cam_left;
	int					i;
}						t_data;

typedef	struct			s_bmp
{
	unsigned int		size_of_file;
	char				*screenshot;
	int					*color;
}						t_bmp;

int						ft_atoi(const char *nptr);
char					**ft_split(char const *s, char c);
char					*ft_substr(char const *s, unsigned int start,
size_t len);
void					*ft_calloc(size_t count, size_t size);
void					*ft_bzero(void *s, size_t n);
char					*ft_strcpy(char *src);
int						ft_isdigit(int c);
int						ft_error_msg(char *s);
int						ft_acces_checker(t_options *qu);
void					ft_all_null_now(t_options *qu);
int						pars_check(t_options *qu, char *line);
int						ft_garbage_check(char *line);
void					ft_cleaner_mass(char **ans);
int						ft_parser_map(t_options *qu);
int						ft_cptain_prise(t_options *qu);
int						ft_check_res(char **ans, int start, int check);
int						ft_check_save(char *save);
int						ft_check_file_name(char *name, char *s);
int						ft_check_0_line_in_map(char *save, char *line);
int						ft_check_argv(t_options *qu, char **argv, int argc);
int						ft_parser_start(t_data *img, int ar, char **arg);
int						ft_pirnt_img_to_screen(t_data *img);
void					ft_texture_set(t_data *img);
unsigned	int			ft_get_background_color(t_data *img, char c);
int						ft_text_init(t_data *img, int n);
void					ft_my_mlx_printer(t_data *data, int x, int y,
int color);
int						ft_init_dda(t_data *img);
void					ft_raycast_srart(t_data *img);
int						ft_sprite_init(t_data *img, int d, int pos);
int						ft_key_2(int keycode, t_data *img);
int						ft_key_3(int keycode, t_data *img);
int						ft_key_press(t_data *img);
int						ft_pirnt_img_to_screen(t_data *img);
void					ft_cleaner(t_data *img);
int						ft_screen_shot(t_data *img);
int						ft_wiev_setup(t_options *qu);
int						ft_key_close(t_data *img);
int						ft_color_control(char **ans, char c, int i, int j);
int						ft_check_color_p2(t_options *qu, int i, char **ans,
char c);
int						ft_check_line_for_split(char *line);
int						ft_check_nubmers(char *s);
int						ft_pos_and_dist_sprites(t_options *qu);
#endif

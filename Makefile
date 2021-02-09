NAME = cub3D

HEADER = ./includes/libcub.h


SRC	= 		./src/map_parser/ft_acces.c\
			./src/map_parser/ft_atoi.c\
			./src/map_parser/ft_check_zero_line_in_map.c\
			./src/map_parser/ft_parser_map.c\
			./src/map_parser/ft_split.c\
			./src/map_parser/get_next_line.c\
			./src/map_parser/get_next_line_utils.c\
			./src/map_parser/parser_start.c\
			./src/map_parser/utils_2.c\
			./src/map_parser/utils.c\
			./src/map_parser/utils_3.c\
			./src/graphic/ray_cast.c\
			./src/graphic/key_press.c\
			./src/graphic/texture.c\
			./src/graphic/dda_setup.c\
			./src/graphic/sprites.c\
			./src/graphic/screenshot_bmp.c\
			./src/graphic/utils_graphic.c\
			./src/map_parser/ft_map_parser_p2.c\

LIB_MLX = libmlx.dylib

MLX = ./minilibx_mms_20200219

FLAGS = -Wall -Wextra -Werror -O2

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_O = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(SRC_O)
		make -C $(MLX)
		mv ./minilibx_mms_20200219/libmlx.dylib ./
		gcc  $(MLX_FLAGS) $(SRC_O) $(LIB_MLX) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:	
	rm -rf $(SRC_O)
	make clean -C $(MLX)

fclean: clean
		rm -rf $(NAME)
		rm -rf $(LIB_MLX)

re: fclean all

.PHONY: all clean fclean re

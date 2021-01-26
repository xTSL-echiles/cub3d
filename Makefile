NAME = 3d

HEADER = ./headers/libcub.h


SRC	= 		./map_parser/ft_acces.c\
			./map_parser/ft_atoi.c\
			./map_parser/ft_check_zero_line_in_map.c\
			./map_parser/ft_parser_map.c\
			./map_parser/ft_split.c\
			./map_parser/get_next_line.c\
			./map_parser/get_next_line_utils.c\
			./map_parser/parser_start.c\
			./map_parser/utils_2.c\
			./map_parser/utils.c\
			./map_parser/utils_3.c\
			./graphic/ray_cast.c\
			./graphic/key_press.c\
			./graphic/texture.c\
			./graphic/DDA_setup.c\
			./graphic/sprites.c\
			./graphic/screenshot_bmp.c

LIB_MLX = ./minilibx_opengl_20191021/libmlx.a

MLX = ./minilibx_opengl_20191021

FLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRC_O = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(SRC_O)
		make -C $(MLX)
		gcc $(MLX_FLAGS) $(SRC_O) $(LIB_MLX) -o $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

clean:	
	rm -rf $(SRC_O)
	make clean -C $(MLX)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

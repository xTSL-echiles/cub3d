NAME = libftprintf.a

SRC	=			ft_printf.c \
				*ft_itoa_base_p.c \
				ft_tolower1.c \
				*ft_itoa_base_x.c \
				ft_print_other.c \
				ft_print_di.c \
				ft_pars_check.c \
				ft_print_s.c \
				ft_print_u.c \
				ft_print_p.c \
				ft_print_x.c \
				ft_print_xx.c \
				ft_print_c.c \
				ft_width.c \
				ft_flag_check.c \
				ft_per.c \
				ft_print_perc.c

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror

SRC_0 = $(patsubst %.c,%.o,$(SRC))

all: $(NAME)

$(NAME): $(SRC_0)
		make -C ./libft
		cp ./libft/libft.a ./$(NAME)
		ar rc $(NAME) $(SRC_0)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -I libft -c $< -o $@

clean:
	make -C ./libft clean
	rm -rf $(SRC_0)

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

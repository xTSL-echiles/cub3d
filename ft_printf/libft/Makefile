# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: echiles <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/31 15:30:06 by echiles           #+#    #+#              #
#    Updated: 2020/10/31 15:53:02 by echiles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC= ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
		ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memccpy.c\
		ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c\
		ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
		ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c\
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_split.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c


SRC_O = $(patsubst %.c,%.o,$(SRC))

HEADERS = libft.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC_O)
	ar rc $(NAME) $(SRC_O)

%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@


clean:
	rm -rf $(SRC_O)

fclean: clean
	rm -rf $(NAME)

re:	fclean all


.PHONY: all clean fclean re bonus

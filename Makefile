# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkartit <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 21:09:09 by mkartit           #+#    #+#              #
#    Updated: 2024/04/27 13:53:31 by mkartit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c\
	 ft_init.c\
	 ft_fractals.c\
	 ft_parsing.c\
	 ft_parsing_utils.c\
	 ft_usagemsg.c\
	 ft_utils.c\
	 ft_colors.c\
	 ft_colors_utils.c\
	 ft_render.c\
	 ft_event.c\
	 ft_event_utils.c\

OBJ = $(SRC:.c=.o)
CC = cc

CFLAGS = -Wall -Wextra -Werror
NAME = fractol

INCLUDES = -I/usr/local/include -Imlx
MLX_FLAGS = -L/use/local/lib -lmlx_Linux -lXext -lX11 -lm


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

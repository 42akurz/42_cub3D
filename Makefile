# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharing <fharing@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/23 14:03:15 by fharing           #+#    #+#              #
#    Updated: 2021/12/14 13:43:09 by fharing          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
PATH_LIBFT = ./libft/libft.a
PATH_MLX = ./mlx/libmlx.a
NAME = cub3D
SOURCES = ./src/main.c ./src/init/calc.c ./src/draw/minimap.c \
			./src/movement/movement.c ./src/init/init.c ./src/logic/hooks.c ./src/logic/math.c ./src/draw/sprite.c \
			./src/draw/texture.c ./src/draw/floor_ceilling.c ./src/error/error.c ./src/movement/walk.c \
			./src/logic/door.c ./src/draw/crosshair.c ./src/draw/draw.c ./src/movement/walk2.c ./src/draw/spell.c \
			./src/init/location.c ./src/parsing/validate_map.c ./src/parsing/validate_map_2.c ./src/parsing/read_files.c ./src/parsing/colour.c \
			./src/logic/mlx.c ./src/error/free.c
OBJECTS = $(SOURCES:.c=.o)

#build everything
all: $(NAME)

#make libft
$(PATH_LIBFT):
	make -C ./libft
	make -C ./mlx

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

#creates a static library
$(NAME): $(PATH_LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(PATH_LIBFT) $(PATH_MLX) -framework OpenGL -framework AppKit -o $(NAME)

norm:
	norminette ./src ./libft ./includes

#removes all *.o files
clean:
	$(RM) $(OBJECTS)
	make clean -C ./libft
	make clean -C ./mlx

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) ./mlx/libmlx.a
	$(RM) cub3D

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all

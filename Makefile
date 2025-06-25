# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 17:01:53 by prambaud          #+#    #+#              #
#    Updated: 2025/03/18 14:21:13 by lbenatar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3d
LIBFT       = libft/libft.a
MLX         = mlx_linux/libmlx.a
SRCS        = ./mlx/main.c \
				./mlx/map_setup.c \
				./mlx/map_parsing.c \
				./mlx/flood_fill.c \
				./mlx/flood_fill_utils.c \
				./mlx/texture_parsing.c \
				./mlx/liberator_god.c \
				./mlx/perso_movement.c \
				./mlx/init_img_data.c \
				./mlx/initializator.c \
				./mlx/play_game.c \
				./mlx/ray_calculator.c \
				./mlx/ray_impact_zone_calculator.c \
				./mlx/image_update.c \
				./mlx/fill_linear_pourcentage_tab.c \
				./mlx/put_lines.c \
				./mlx/color_parsing.c \
				./mlx/parsing_occurence_infos.c \
				./mlx/init_pre_img_data.c \
				./mlx/map_parsing_closed.c \
				./mlx/map_setup_second.c \
				./mlx/texture_parsing_second.c \
				./mlx/utils.c

OBJ_DIR     = ./mlx/object
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -rf

# Construction de l'exécutable
${NAME}: ${LIBFT} ${MLX} ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Lmlx_linux -lmlx -L/usr/lib \
		-Imlx_linux -lXext -lX11 -lm  -lz -Llibft -lft -o ${NAME}

# Compilation de libft
${LIBFT}:
	make -C libft

# Compilation de libmlx
${MLX}:
	make -C mlx_linux

# Création du dossier object si nécessaire et compilation des .c en .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -Imlx_linux -c $< -o $@

# Création du dossier object si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/mlx

# Règles principales
all: ${NAME}

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJ_DIR}

fclean: clean
	make fclean -C libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

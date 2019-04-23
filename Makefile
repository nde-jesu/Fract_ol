# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/16 08:17:01 by nde-jesu          #+#    #+#              #
#    Updated: 2019/04/23 15:38:00 by nde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# You can change here

# Executable's name
NAME = fractol

# Directories needed
SRC_DIR = ./srcs/
OBJ_DIR = ./obj/
HEADERS_DIR = ./includes/
LIBFT_DIR = ./Libft/
MLX_DIR = /usr/local/lib/

# Source files
SRC_LIST = main.c image_control.c init.c mandelbrot.c julia.c menu.c control.c \
		   command.c mouse.c barnsley.c color.c utils.c zoom.c
SRC_LIBFT = $(LIBFT_DIR)libft.a
SRC_MLX = $(MLX_DIR)libmlx.a

# Include files
HEADERS_LIST = fractol.h mlx_macro_keys.h
LIBFT_HEAD = $(LIBFT_DIR)includes/
MLX_HEAD = $(MLX_DIR)/../include/mlx.h

# Color codes
YELLOW = \033[033m
GREEN = \033[032m
BLUE = \033[36m
RED = \033[031m
PURPLE = \033[35m
RESET = \033[0m

# How files have to be compiled
CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEAD) -I$(MLX_HEAD)
LIBRARIES = -lmlx -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL \
			-framework AppKit

# Please try not to change after this

# Some makefile tricks
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	@echo "$(PURPLE)\n	- Building project: $(RESET)$(NAME)\n"
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJ) -o $(NAME)
	@echo "$(GREEN)***	Project $(NAME) successfully compiled ***$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(YELLOW)	- Compiling: $(RESET)" $<

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)***	Deleting all objects from $(NAME)	***\n$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)
	@echo "$(RED)***	Deleting executable file from $(NAME)	***\n$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all

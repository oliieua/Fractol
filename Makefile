# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ooliinyk <ooliinyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 17:05:43 by ooliinyk          #+#    #+#              #
#    Updated: 2019/07/03 15:07:12 by ooliinyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

SRC_DIR := ./src/
OBJ_DIR := ./obj/
INC_DIR := ./inc/
LIB_DIR := ./lib/

SRC := main.c hot_keys.c init.c fractals.c colors.c zoom.c fractals_h.c usage.c

OBJ := $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR := $(LIB_DIR)libft/
LIBFT_INC := $(LIBFT_DIR)includes/
LIBFT_FLAGS := -lft -L $(LIBFT_DIR)

CC_FLAGS := -Wall -Wextra -Werror -O3

LINK_FLAGS := $(LIBFT_FLAGS)

HEADER_FLAGS := -I $(INC_DIR) -I $(LIBFT_DIR)

MLX_FLAGS := -framework AppKit -framework OpenGL -lmlx

CC := gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LINK_FLAGS) $(MLX_FLAGS) -o $(NAME)

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)

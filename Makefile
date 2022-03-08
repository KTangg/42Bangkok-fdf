# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 18:33:16 by spoolpra          #+#    #+#              #
#    Updated: 2022/03/08 13:44:46 by spoolpra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC_DIR = srcs/
OBJ_DIR = objs/
LIB_DIR = libft/
MLX_DIR = /usr/local/lib/minilibx

INCS = -Iincludes/ -I$(LIB_DIR)includes/ -I$(MLX_DIR)
NAME = fdf
PARSING = parsing/parsing_file.c parsing/parsing_error.c parsing/parsing_utils.c parsing/parsing_attribute.c
RENDER = render/render.c render/vector.c render/image.c render/draw.c render/coor.c
EVENT = event/keyboard.c event/mouse.c
SRCS = fdf.c free.c error.c $(PARSING) $(RENDER) $(EVENT)
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR),$(OBJS))
	@make -C $(LIB_DIR) --silent
	$(CC) $^ -o $(NAME) -L $(LIB_DIR) -L $(MLX_DIR) -lmlx -lft -lmlx -lXext -lX11 -lm
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/parsing
	@mkdir -p $(OBJ_DIR)/render
	@mkdir -p $(OBJ_DIR)/event
	$(CC) $(CFLAGS) -c $< $(INCS) -o $@
bonus: $(NAME)
clean:
	@make -C $(LIB_DIR) clean --silent
	$(RM) $(OBJ_DIR)
fclean: clean
	@make -C $(LIB_DIR) fclean --silent
	$(RM) $(NAME)
re: fclean all

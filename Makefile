# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/17 17:25:22 by camarcos          #+#    #+#              #
#    Updated: 2024/12/19 13:08:15 by camarcos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME = FRACTOL

# LIBFT
LIBFT = libft/libft.a

# SOURCE FILES
SRC =	src/utils.c \
		src/fractol.c \
		src/init.c \
		src/mandel_julia.c \
		src/mouse_keys.c \

# OBJECT FILES
OBJ_FILES = $(SRC:.c=.o)

# COMPILER OPTIONS 
CC = gcc
FLAGS = -Wall -Werror -Wextra -g3
MLX = -L minilibx-linux -lmlx -lXext -lX11 -lm
INCLUDE = -I includes
RM = rm -f

# COLORS
RED = \033[91;1m
GREEN = \033[92;1m
YELLOW = \033[93;1m
BLUE = \033[94;1m
PINK = \033[95;1m
CLEAR = \033[0m

# MAKEFILE RULES
all: $(NAME)

minilibx-linux/libmlx.a:
	@echo "$(YELLOW)Compiling MinilibX library$(CLEAR)"
	@make -sC minilibx-linux

$(NAME): minilibx-linux/libmlx.a $(OBJ_FILES)
	@make -sC libft
	@echo "$(PINK)Compiling the FRAC-OL program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) $(INCLUDE) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -sC libft
	$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC libft
	$(RM) $(NAME) minilibx-linux/libmlx.a
	@echo "$(PINK)Removing exec. files.$(CLEAR)"
	$(RM) $(NAME)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re

t: all
	@cp $(NAME) tester/

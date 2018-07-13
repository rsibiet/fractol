# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/18 11:54:12 by rsibiet           #+#    #+#              #
#    Updated: 2016/02/20 15:52:53 by rsibiet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FTC = main_fractol.c \
	  error_fractol.c \
	  draw_fractol.c \
	  legend_fractol.c

FTO = $(subst .c,.o,$(FTC))

MLX = -L./MinilibX/ -lmlx -framework OpenGL -framework AppKit

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(FTO)
	@echo ""
	@make -C ./libft
	@make -C ./MinilibX
	@gcc -o $(NAME) $(FTO) ./libft/libft.a $(MLX)
	@echo "\033[32m$(NAME) created!\033[0m"

%.o: %.c
	@gcc -Wall -Wextra -Werror -I./libft/ -c $<
	@echo "\033[36m#\033[0m\c"

clean:
	@make -C ./libft clean
	@make -C ./MinilibX clean
	@rm -rf $(FTO)
	@echo "\033[33m$(NAME) object deleted!\033[0m"

fclean: clean
	@make -C ./libft fcleana
	@rm -rf $(NAME)
	@echo "\033[31m$(NAME) deleted!\033[0m"

re: fclean all

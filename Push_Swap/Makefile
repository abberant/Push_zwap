# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 18:06:06 by aanouari          #+#    #+#              #
#    Updated: 2023/04/07 01:47:58 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pushswap


SRCS =		$(wildcard *.c) $(wildcard ./libft/*.c)


NO_COLOR	=	\033[0m
GREEN		=	\033[0;1;92m
RED			=	\033[0;1;91m
BLUE		=	\33[0;1;94m


OBJ = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g


RM = rm -rf


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RED)\r LOADING...🕛$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕐$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕑$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕒$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕓$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕔$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕕$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕖$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕗$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕘$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕙$(NO_COLOR)"
	@sleep 0.01
	@printf "$(RED)\r LOADING...🕚$(NO_COLOR)"
	@sleep 0.01


all:		$(NAME)


$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@printf "$(GREEN)\r SUCCESSFULLY COMPILED!!\n$(NO_COLOR)"


clean:
				@$(RM) $(OBJ)
				@printf "$(BLUE)\r Done Cleaning!!\n$(NO_COLOR)"


fclean:			clean
				@$(RM) $(NAME)


re:				fclean all
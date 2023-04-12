# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 18:07:06 by aanouari          #+#    #+#              #
#    Updated: 2023/04/11 18:19:58 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	$(wildcard *.c)

OBJS		=	$(SRCS:.c=.o)

CFLAGS		=	-Wall -Wextra -Werror
CC			=	cc
RM			=	rm -rf

NO_COLOR	=	\033[0m
GREEN		=	\033[0;1;92m
RED			=	\033[0;1;91m
BLUE		=	\33[0;1;94m

.c.o		:
				@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
				@printf "$(RED)\r LOADING...⏳$(NO_COLOR)"

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean		:
				@$(RM) $(OBJS)

fclean		:	clean
				@$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
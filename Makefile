# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 18:06:06 by aanouari          #+#    #+#              #
#    Updated: 2023/04/11 18:25:18 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CNAME		=	checker

NO_COLOR	=	\033[0m
GREEN		=	\033[0;1;92m
RED			=	\033[0;1;91m
BLUE		=	\33[0;1;94m

CC 	=		cc
CFLAGS =	-Wall -Wextra -Werror
RM =		rm -rf

_SRCS =		utils.c stack_org.c stack_org2.c minor_utils.c \
			executing_moves.c stack_b_utils.c push_swap.c \
			ps_operations.c ps_operations2.c ps_operations3.c \
			ps_operations4.c
SRCS =		$(addprefix mandatory/, $(_SRCS))
OBJS =		$(SRCS:.c=.o)

_CSRCS =	checker.c
CSRCS = 	$(addprefix bonus/, $(_CSRCS))
COBJS =		$(CSRCS:.c=.o)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "$(RED)\r LOADING...⏳$(NO_COLOR)"
	

all:		$(NAME)

$(NAME):$(OBJS) mandatory/test.o
		@make -C libft/
		@$(CC) $(CFLAGS) -L libft/ -lft mandatory/test.o $(OBJS) -o $(NAME)
		@printf "$(GREEN)\r SUCCESSFULLY COMPILED!!\n$(NO_COLOR)"
		
bonus:	$(OBJS) $(COBJS) bonus/main.o
		@make -C libft/
		@$(CC) $(CFLAGS) -L libft/ -lft bonus/main.o $(OBJS) $(COBJS) -o $(CNAME)
		@printf "$(GREEN)\r BONUS SUCCESSFULLY COMPILED!!\n$(NO_COLOR)"

clean:
				@$(RM) $(OBJS) $(COBJS) mandatory/test.o bonus/main.o
				@printf "$(BLUE)\r Done Cleaning!!\n$(NO_COLOR)"
				@make clean -C libft/


fclean:			clean
				@$(RM) $(NAME) $(CNAME)
				@make fclean -C libft/


re:				fclean all

.PHONY	:	all clean fclean re bonus

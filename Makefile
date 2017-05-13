# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qho <qho@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/13 10:22:45 by qho               #+#    #+#              #
#    Updated: 2017/05/13 15:41:39 by qho              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	hotrace

# Flags and compiler
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

# Source and header files, and directory
INC		=	./inc/
FILES	=	main get_next_line ft_bzero ft_strchr ft_strdup ft_strjoin \
			ft_putchar ft_putstr ft_putendl ft_strlen ft_strcpy ft_strcmp \


SRC		=	$(addprefix src/, $(addsuffix .c, $(FILES)))

# Object directory and files
OBJ	=	$(addsuffix .o, $(FILES))

.PHONY: clean fclean re norm

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) -I$(INC) $(SRC) -o $(NAME)
	@echo "\033[32m$(NAME) compiled\033[0m"

test:
	@$(CC) -I$(INC) $(T_SRC) -o $(NAME)

norm:
	@norminette $(SRC) $(INC)

clean:
	@/bin/rm -rf $(OBJ)
	@echo "\033[31mCleaning object files\033[0m"

fclean: clean
	@/bin/rm -f $(NAME) $(EXE)
	@echo "\033[31mCleaning $(NAME)\033[0m"

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmore <pmore@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/08 12:07:18 by pmore             #+#    #+#              #
#    Updated: 2019/04/08 12:12:32 by pmore            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_malloc
INCLUDES = libft
SRCS = main.c # ft_malloc.c
OBJECTS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror
LIB = libft

all: $(NAME)

$(NAME):
	@cd $(LIB) ; $(MAKE)
	gcc -g $(FLAGS) -c $(SRCS) -I $(INCLUDES)
	gcc -g $(OBJECTS) -L libft/ -lft -o $(NAME) -ltermcap
	@cd $(LIB) ; $(MAKE) fclean
	@echo Creating $(NAME)...

clean:
	/bin/rm -f $(OBJECTS)
	/bin/rm -f *~
	@echo Removing $(OBJECTS)...

fclean: clean
	/bin/rm -f $(NAME)
	@echo Removing $(NAME)...

re: fclean all

.PHONY: clean fclean re

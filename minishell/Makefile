# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riramli <riramli@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 11:23:18 by riramli           #+#    #+#              #
#    Updated: 2022/06/09 16:42:21 by riramli          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	 	= minishell
FLAG		= -Wall -Wextra -Werror -g -fsanitize=address -lreadline -Wno-unused-result -Wno-unused-parameter -Wno-unused-variable
LIBFT_DIR = libft

all:	$(NAME)

#make -C $(LIBFT_DIR)/
#gcc main.c -L $(LIBFT_DIR)*.a -o $(NAME)
$(NAME):
	make -C $(LIBFT_DIR)/
	gcc -c -Iinc src/*.c
	gcc $(FLAG) main.c -Iinc *.o $(LIBFT_DIR)/*.a -o $(NAME)

clean:
		rm -f *.o

fclean: clean
		rm $(NAME)

re:		fclean all

t:		re
	./$(NAME)

.PHONY: all run clean

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xacoquan <xacoquan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 22:51:38 by xacoquan          #+#    #+#              #
#    Updated: 2015/03/23 14:02:33 by xacoquan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_select
VERSION=1.0.0
CFLAGS=-Wall -Werror -Wextra -g 
INCLUDES=-I ./libft/includes
LIBS=-L ./libft -l ft

SRC=main.c \
	list.c \
	divers.c \
	singleton.c \
	term_init_close.c \
	move_position.c \
	list_delete_node.c \
	check.c \
	signal.c \
	print.c \

OBJ=$(SRC:.c=.o)

all: build $(NAME) finish

build:
	@($(MAKE) -C ./libft)

$(NAME): $(OBJ) ./libft/libft.a
	gcc $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ) $(LIBS) -ltermcap

%.o: %.c ./libft/includes
	gcc $(CFLAGS) $(INCLUDES) -o $@ -c $<

clean:
	@(rm -rf $(OBJ))

fclean: clean
	@(rm -rf $(NAME))
	@($(MAKE) -C ./libft fclean)

re: fclean all

v:
	@(echo "version: $(VERSION)")

finish:
	@(echo "[\033[32m$(NAME)\033[00m]")

.PHONY: all build clean fclean re v

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 01:29:55 by gbudau            #+#    #+#              #
#    Updated: 2020/02/11 01:51:37 by gbudau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = libft
LIB = libft.a
DEPS = ft_printf.h
OBJ = ft_printf.o

.PHONY: all
all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/$(LIB) $(NAME)
	ar rcs $(NAME) $^

.PHONY: clean
clean:
	make -C $(LIB_DIR) $@
	$(RM) $(OBJ)

.PHONY: fclean
fclean: clean
	make -C $(LIB_DIR) $@
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: re
	$(CC) $(CFLAGS) $@.c -L. -lftprintf -o $@ -g && ./$@ | cat -e

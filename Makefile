# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbudau <gbudau@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/09 01:29:55 by gbudau            #+#    #+#              #
#    Updated: 2020/02/12 06:11:05 by gbudau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --silent

I_DIR = include
SRC_DIR = src
O_DIR = obj
L_DIR = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -c -o
AR = ar rcs
RMF = rm -rf

NAME = libftprintf.a
LIB = libft.a

_OBJ = ft_printf.o
OBJ := $(patsubst %, $(O_DIR)/%, $(_OBJ))


_DEPS = ft_printf.h
DEPS := $(patsubst %, $(I_DIR)/%, $(_DEPS))

.PHONY: all
all: $(NAME)

$(O_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) $(OFLAGS) $@ $<

$(OBJ): | $(O_DIR)

$(O_DIR):
	mkdir $(O_DIR)

$(NAME): $(OBJ)
	make -C $(L_DIR) bonus
	cp $(L_DIR)/$(LIB) $(NAME)
	$(AR) $(NAME) $^

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	make -C $(L_DIR) fclean
	$(RMF) $(O_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: test
test: re
	$(CC) $(CFLAGS) main.c -L. -lftprintf -o a.out && ./a.out | cat -e

.PHONY: debug
debug: CFLAGS += -g
debug: test

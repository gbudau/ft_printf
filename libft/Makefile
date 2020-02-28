# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gbudau <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/11 00:42:18 by gbudau            #+#    #+#              #
#    Updated: 2020/02/28 15:16:30 by gbudau           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE.c = $(CC) $(CFLAGS) -c
DEPS = libft.h
OUTPUT_OPTION = -o $@
AR = ar rcs
OBJ = ft_isalnum.o ft_putchar_fd.o ft_putnbr_fd.o ft_memcmp.o ft_atoi.o ft_strnstr.o \
      ft_isspace.o ft_memset.o ft_strlcpy.o ft_strlen.o ft_putendl_fd.o \
      ft_split.o ft_bzero.o ft_isalpha.o ft_strncmp.o ft_memccpy.o ft_strmapi.o \
      ft_toupper.o ft_substr.o ft_isascii.o ft_calloc.o ft_strchr.o ft_memmove.o \
      ft_itoa.o ft_strrchr.o ft_strjoin.o ft_isdigit.o ft_strlcat.o ft_putstr_fd.o \
      ft_memcpy.o ft_tolower.o ft_strtrim.o ft_strdup.o ft_memchr.o ft_isprint.o
EXTRA = ft_strndup.o ft_nblen.o ft_putnbr.o ft_putchar.o ft_strrev.o ft_strchr_index.o \
	ft_putstr.o ft_strnrevn.o ft_strnrevn.o ft_strcpy.o
BON_OBJ = ft_lstclear_bonus.o ft_lstmap_bonus.o ft_lstnew_bonus.o ft_lstsize_bonus.o \
          ft_lstdelone_bonus.o ft_lstadd_front_bonus.o ft_lstiter_bonus.o \
          ft_lstadd_back_bonus.o ft_lstlast_bonus.o 

.PHONY: all
all: $(NAME)

%.o: %.c $(DEPS)
	$(COMPILE.c) $< $(OUTPUT_OPTION)

$(NAME): $(OBJ) $(EXTRA) $(BON_OBJ) 
	$(AR) $@ $^

.PHONY: clean
clean:
	$(RM) $(OBJ) $(EXTRA) $(BON_OBJ)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

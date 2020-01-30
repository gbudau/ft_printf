NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB_DIR = libft
LIB = libft.a
AR_FLAGS = rcs
DEPS = ft_printf.h
OBJ = ft_printf.o

.PHONY: all
all: $(NAME)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIB_DIR) bonus
	cp $(LIB_DIR)/$(LIB) $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $^

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
	$(CC) $(CFLAGS) $@.c -L. -lftprintf -o $@ && ./$@

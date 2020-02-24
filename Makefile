
CHECKER_NAME = checker
PS_NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = procedure.c parse1.c parse2.c ft_atoi_backsp.c \
	funs1.c funs2.c funs3.c funs4.c \
	sort2.c set.c sort3.c sort4.c fun_print.c check_conditions.c \
	act1.c act2.c sort41.c sort42.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = ps_header.h

LIBFT_PATH = my_libft
LIBFT = $(LIBFT_PATH)/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE = "\033[0m"

.PHONY: all clean fclean re

all: $(PS_NAME)

$(PS_NAME): $(LIBFT) $(OBJECTS)
		@$(CC) $(CFLAGS) -o $(PS_NAME) push_swap.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@$(CC) $(CFLAGS) -o $(CHECKER_NAME) checker.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft

$(OBJECTS): %.o: %.c
		@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
		@echo push_swap: $(GREEN) $< $(WHITE)

$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		@/bin/rm -f $(PS_NAME)
		@/bin/rm -f $(CHECKER_NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

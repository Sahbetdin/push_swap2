
CHECKER_NAME = checker
PS_NAME = push_swap
NAME = $(PS_NAME) #$(CHECKER_NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = parse_args.c ft_atoi_backsp.c funs1.c ps.c sort2.c \
	set.c sort3.c sort4.c fun_print.c check_conditions.c \
	act1.c sort41.c sort42.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = ps_header.h

LIBFT_PATH = my_libft
LIBFT = $(LIBFT_PATH)/libft.a


RED = "\033[0;31m" #???
GREEN = "\033[0;32m"
WHITE = "\033[0m"


.PHONY: all clean fclean re

all: $(PS_NAME)

$(PS_NAME): $(LIBFT) $(OBJECTS)
		@$(CC) -o $(PS_NAME) push_swap.c $(OBJECTS) -I $(LIBFT_PATH)includes -L \
		$(LIBFT_PATH) -lft

$(OBJECTS): %.o: %.c
		@$(CC) -I $(HEADER) -o $@ -c $<
		@echo Push_swap: $(GREEN) $< $(WHITE)


$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)

ch:	$(OBJECTS)
		@$(CC) -o $(CHECKER_NAME) checker.c $(OBJECTS) -I $(LIBFT_PATH)includes -L \
		$(LIBFT_PATH) -lft


test:	all
#		@./push_swap test

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		@/bin/rm -f $(PS_NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

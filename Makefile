NAME = push_swap

SRC = parse_args.c ft_atoi_backsp.c funs1.c ps.c sort2.c sort3.c sort4.c fun_print.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = ps_header.h

LIBFT = $(LIBFT_PATH) libft.a
LIBFT_PATH = my_libft/
CC = gcc
FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
		@$(CC) -o $(NAME) $(OBJECTS) -I $(LIBFT_PATH)includes -L \
		$(LIBFT_PATH) -lft

$(OBJECTS): %.o: %.c
		@$(CC) -I $(HEADER) -o $@ -c $<


$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH)

test:	all
#		@./push_swap test

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
		@/bin/rm -f $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = main.c \
          stack.c stack_ops.c \
          ops_basic.c ops_utils.c ops_rotate_a_b.c ops_rotate_dual.c \
          atoi_safe.c parse_read.c parse_count.c \
          check_sorted.c errors.c rank.c solve_small.c solve_chunks.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c stack.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


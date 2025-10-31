CC	:= gcc
CFLAGS	:= -Wall -Wextra -Werror -g fsanitize=address

NAME	:= main

SRC	:= test2.c ../test/get_next_line.c ../test/get_next_line_utils.c
OBJ	:= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

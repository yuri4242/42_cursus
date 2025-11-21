LIBFT_DIR	:= ./Libft

LIBFT_A	:= $(LIBFT_DIR)/libft.a

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -I$(LIBFT_DIR)

NAME	:= pipex

HEADER	:= ft_pipex.h

SRCS := \
		ft_pipex.c \
		cmd1.c     \
		utils1.c   \
		utils2.c

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)

$(LIBFT_A):
	make all -C $(LIBFT_DIR)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

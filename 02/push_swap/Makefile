HEADER_DIR	:= ./
LIBFT_DIR	:= ./src/Libft

INCLUDES	:= -I$(LIBFT_DIR) -I$(HEADER_DIR)

LIBFT_FLAGS	:= -L$(LIBFT_DIR) -lft

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror -fsanitize=address -g

NAME	:= push_swap


SRCS := \
		./main.c                       \
		./args_to_lst.c       \
		./check_args.c       \
		./create_and_free_stacks.c    \
		./ps_list_operation.c        \
		./ps_split.c \
		./utils.c \
		./swap.c \
		./push.c \
		./rotate.c \
		./reverse_rotate.c \
		./two_sort.c

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@printf "\r\033[K\033[32mCompiling Done!!\033[0m"
	@echo "\n\033[32mCreating $(NAME)...\033[0m"
	@make -s -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS)
	@echo "\033[32mCreating $(NAME) Done!!\033[0m"

%.o: %.c
	@printf "\r\033[K\033[32mCompiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[33mCleaning object files...\033[0m"
	@make -s clean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(OBJS)
	@echo "\033[33mCleaning Done!!\033[0m"

fclean: clean
	@echo "\033[31mRemoving binary...\033[0m"
	@make -s fclean -C $(LIBFT_DIR) > /dev/null 
	@rm -f $(NAME)
	@echo "\033[31mRemoving Done!!\033[0m"

re: fclean all

.PHONY: all clean fclean re

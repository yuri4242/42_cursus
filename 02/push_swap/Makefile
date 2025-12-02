HEADER_DIR	:= ./include
LIBFT_DIR	:= ./src/Libft

INCLUDES	:= -I$(LIBFT_DIR) -I$(HEADER_DIR)

LIBFT_FLAGS	:= -L$(LIBFT_DIR) -lft

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror

NAME	:= push_swap

SRCS := \
		./src/main.c                         \
		./src/args/args_to_lst.c             \
		./src/args/check_args.c              \
		./src/args/ps_list_operation.c       \
		./src/args/ps_split.c                \
		./src/operation/swap.c               \
		./src/operation/push.c               \
		./src/operation/rotate.c             \
		./src/operation/reverse_rotate.c     \
		./src/small_sort/two_sort.c          \
		./src/small_sort/three_sort.c        \
		./src/small_sort/four_five_sort.c    \
		./src/large_sort/large_sort.c        \
		./src/large_sort/move_to_a.c         \
		./src/large_sort/update_node_info.c  \
		./src/large_sort/both_rotate.c       \
		./src/utils/create_and_free_stacks.c \
		./src/utils/utils.c                  \
		./src/utils/coordinate_compression.c 

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

LIBFT_DIR	:= ./Libft
MLX_DIR	:= $(HOME)/minilibx

INCLUDES	:= -I$(LIBFT_DIR) -I$(MLX_DIR)

LIBFT_FLAGS	:= -L$(LIBFT_DIR) -lft
MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror

NAME	:= so_long

HEADER	:= so_long.h

SRCS := \
		main.c              \
		check_chars.c       \
		check_input.c       \
		check_path.c        \
		check_rectangular.c \
		check_wall.c        \
		close_game.c        \
		draw_map.c          \
		key_press.c         \
		launch_window.c     \
		move_player.c       \
		read_map.c          \
		set_img.c           \
		start_game.c        \
		validate_map.c

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@printf "\r\033[K\033[32mCompiling Done!!\033[0m"
	@echo "\n\033[32mCreating $(NAME)...\033[0m"
	@make -s -C $(LIBFT_DIR) > /dev/null
	@make -s -C $(MLX_DIR) > /dev/null 2>&1
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)
	@echo "\033[32mCreating $(NAME) Done!!\033[0m"

%.o: %.c $(HEADER)
	@printf "\r\033[K\033[32mCompiling $<\033[0m"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "\033[33mCleaning object files...\033[0m"
	@make -s clean -C $(LIBFT_DIR) > /dev/null
	@make -s clean -C $(MLX_DIR) > /dev/null
	@rm -f $(OBJS)
	@echo "\033[33mCleaning Done!!\033[0m"

fclean: clean
	@echo "\033[31mRemoving binary...\033[0m"
	@make -s fclean -C $(LIBFT_DIR) > /dev/null 
	@rm -f $(NAME)
	@echo "\033[31mRemoving Done!!\033[0m"

re: fclean all

.PHONY: all clean fclean re

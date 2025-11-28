HEADER_DIR	:= ./include
LIBFT_DIR	:= ./src/Libft
MLX_DIR	:= $(HOME)/minilibx

INCLUDES	:= -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(HEADER_DIR)

LIBFT_FLAGS	:= -L$(LIBFT_DIR) -lft
MLX_FLAGS	:= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

CC	:= cc
CFLAGS	:= -Wall -Wextra -Werror

NAME	:= so_long

HEADER	:= $(HEADER_DIR)/so_long.h

SRCS := \
		./src/main.c                       \
		./src/checkers/check_chars.c       \
		./src/checkers/check_input.c       \
		./src/checkers/check_map_size.c    \
		./src/checkers/check_path.c        \
		./src/checkers/check_rectangular.c \
		./src/checkers/check_wall.c        \
		./src/game/close_game.c            \
		./src/game/start_game.c            \
		./src/map/draw_map.c               \
		./src/map/read_map.c               \
		./src/map/validate_map.c           \
		./src/process/key_press.c          \
		./src/process/launch_window.c      \
		./src/process/move_player.c        \
		./src/process/set_img.c

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

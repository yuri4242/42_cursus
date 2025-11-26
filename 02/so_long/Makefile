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
		main.c          \
		draw_map.c      \
		launch_window.c \
		read_map.c      \
		set_img.c       \
		start_game.c 

OBJS	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MLX_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_FLAGS) $(MLX_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@make -s clean -C $(MLX_DIR) > /dev/null 2>&1
	rm -f $(OBJS)

fclean: clean
	@make -s fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

SRCS_DIR	:= .
PRINT_DIR	:= ./print
HEADER_DIR	:= ./header
PARSE_DIR	:= ./parse
UTIL_DIR	:= ./util
LIBFT_PATH	:= ./Libft

LIBFT_A	:= $(LIBFT_PATH)/libft.a

CC	:= gcc
#CFLAGS	:= -Wall -Wextra -Werror

CPPFLAGS	:= -I$(LIBFT_PATH) -I$(HEADER_DIR)
LDFLAGS	:= -L$(LIBFT_PATH) -lft

AR	:= ar
ARFLAGS	:= rs

NAME	:= test

HEADERS	:= $(HEADER_DIR)/ft_printf.h \
		   $(HEADER_DIR)/print.h \
		   $(PARSE_DIR)/parse.h \
		   $(HEADER_DIR)/util.h 

SRC_TEST := \
			ft_printf.c  \
			main.c

SRC_PRINT	:= \
			   print_char.c \
			   print_str.c \
			   print_pointer.c \
			   print_signed_nbr.c \
			   print_unsigned_nbr.c \
			   print_hex_lower.c \
			   print_hex_upper.c \
			   print_hex_integer.c

SRC_PARSE	:= \
			   parse_specifier.c \
			   parse_flag.c \
			   parse_width.c \
			   parse_precision.c

SRC_UTIL	:= \
			   ptf_putchar.c \
			   ptf_putstr.c \
			   ptf_putnbr_hex.c \
			   ptf_putnbr_hex_upper.c \
			   ptf_putnbr.c \
			   ptf_putnbr_unsigned.c \
			   ptf_putnbr_absolute.c \
			   ptf_putnbr_base.c \
			   is_flag_specifier.c \
			   init_flags.c \
			   ptf_print_padding.c \
			   get_hex_len.c \
			   get_decimal_len.c \
			   write_check.c

SRCS	:= $(addprefix $(SRCS_DIR)/, $(SRC_TEST)) \
		   $(addprefix $(PRINT_DIR)/, $(SRC_PRINT)) \
		   $(addprefix $(PARSE_DIR)/, $(SRC_PARSE)) \
		   $(addprefix $(UTIL_DIR)/, $(SRC_UTIL))
OBJ	:= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
#	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_PATH)

%.o: %.c $(HEADERS)
	$(CC) $(CPPFLAGS) -c $< -o $@
#	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re bonus

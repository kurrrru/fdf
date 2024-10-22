NAME		=	fdf
SRCS		=	main.c \
				error_argc.c \
				error_extension.c \
				is_valid_extension.c
OBJS		=	$(SRCS:.c=.o)

# Libft
LIBFT_DIR	=	libft
LIBFT_NAME	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)

# Minilibx
MLX_DIR		=	minilibx-linux
MLX_NAME	=	libmlx_Linux.a
MLX			=	$(MLX_DIR)/$(MLX_NAME)

# Compiler settings
CC			=	cc
LIB_FLAGS	=	-L$(MLX_DIR) -lmlx -lXext -lX11 -lm -L$(LIBFT_DIR) -lft
CFLAGS		=	-Wall -Wextra -Werror

# Remove command
RM			=	rm -f

.DEFAULT_GOAL = all

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(LIB_FLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

all: $(NAME)

.PHONY: all clean fclean re

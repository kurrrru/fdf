NAME		=	fdf
SRCS		=	main.c \
				fdf.c \
				param_check.c \
				parse_map.c \
				free_xd.c \
				wrap_file_manip.c \
				wrap_memory.c \
				wrap_mlx.c \
				atoi_check.c \
				atox_check.c \
				fdf_atoi.c \
				fdf_atox.c \
				map_init.c \
				hook.c \
				draw_line.c \
				draw_point.c \
				draw_map.c \
				isometric.c \
				isometric_subfunc.c \
				fdf_math.c \
				fdf_math_d.c \
				fdf_linear_algebra.c \
				rotate.c \
				shift_center.c

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
DEBUG		=	-fsanitize=address
LFLAGS		=	-Wall -Wextra -Werror -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lXext -lX11 -lm -lbsd
CFLAGS		=	-Wall -Wextra -Werror -I$(MLX_DIR) -I$(LIBFT_DIR) -I. -I%%%%

CFLAGS		+=	$(DEBUG)
LFLAGS		+=	$(DEBUG)

# Remove command
RM			=	rm -f

.DEFAULT_GOAL = all

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

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

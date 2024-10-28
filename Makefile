NAME		=	fdf
SRCS		=	m_main.c \
				m_fdf.c \
				m_param_check.c \
				m_parse_map.c \
				m_free_xd.c \
				m_wrap_file_manip.c \
				m_wrap_memory.c \
				m_wrap_mlx.c \
				m_atoi_check.c \
				m_atox_check.c \
				m_fdf_atoi.c \
				m_fdf_atox.c \
				m_map_init.c \
				m_hook.c \
				m_draw_line.c \
				m_draw_point.c \
				m_draw_map.c \
				m_isometric.c \
				m_isometric_subfunc.c \
				m_fdf_math.c \
				m_fdf_math_d.c \
				m_fdf_linear_algebra.c \
				m_rotate.c \
				m_shift_center.c

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

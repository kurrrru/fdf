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

BONUS_SRCS	=	b_atoi_check_bonus.c \
				b_atox_check_bonus.c \
				b_draw_line_bonus.c \
				b_draw_map_bonus.c \
				b_draw_point_bonus.c \
				b_fdf_atoi_bonus.c \
				b_fdf_atox_bonus.c \
				b_fdf_bonus.c \
				b_fdf_linear_algebra_bonus.c \
				b_fdf_math_bonus.c \
				b_fdf_math_d_bonus.c \
				b_free_xd_bonus.c \
				b_hook_bonus.c \
				b_is_crossing_bonus.c \
				b_isometric_bonus.c \
				b_set_color_bonus.c \
				b_main_bonus.c \
				b_map_init_bonus.c \
				b_param_check_bonus.c \
				b_parse_map_bonus.c \
				b_rotate_bonus.c \
				b_shift_center_bonus.c \
				b_wrap_file_manip_bonus.c \
				b_wrap_memory_bonus.c \
				b_wrap_mlx_bonus.c \
				b_map_update_bonus.c \
				b_hook_rotate_bonus.c \
				b_hook_zoom_bonus.c \
				b_hook_move_bonus.c \
				b_hook_color_bonus.c \
				b_parallel_front_bonus.c \
				b_parallel_top_bonus.c \
				b_parallel_right_bonus.c \
				b_calc_coordinate_bonus.c \
				b_size_adjust_bonus.c \
				b_key_hook_loop_bonus.c \
				bs_stl_bonus.c \
				bs_read_bonus.c \
				bs_draw_point_bonus.c \
				bs_draw_tri_bonus.c \
				bs_draw_stl_bonus.c \
				bs_hook_bonus.c \
				bs_size_adjust_bonus.c \
				bs_hook_move_bonus.c \
				bs_hook_rotate_bonus.c \
				bs_hook_zoom_bonus.c \
				bs_key_hook_loop_bonus.c \
				bs_need_to_draw_bonus.c

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

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

# CFLAGS		+=	$(DEBUG)
# LFLAGS		+=	$(DEBUG)

# Remove command
RM			=	rm -f

.DEFAULT_GOAL = all

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
	SRCS = $(BONUS)
	OBJS = $(BONUS_OBJS)
endif

$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o: %.c
	$(CC) -o $@ $(CFLAGS) -c $<

$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX):
	make -C $(MLX_DIR)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

all: $(NAME)

bonus: $(NAME)

.PHONY: all clean fclean re bonus

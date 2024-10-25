/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:24:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 14:50:10 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1
# define ERROR -1

# define PROPER_ARGC 2
# define MSG_USAGE "Usage Error: ./fdf [*.fdf]"
# define COLOR_MAX 0xFFFFFF

# define PROPER_EXTENSION ".fdf"
# define PROPER_EXTENSION_LEN 4
# define MSG_EXTENSION_ERROR "Extension Error: \
The extension of the file must be \".fdf\""
# define MSG_REALLOC_SIZE_ERROR "realloc_wrap: new_size must be \
greater than old_size"
# define MSG_WIDTH_NOT_EQUAL "parse_file: The width of the map is not constant"
# define MSG_MAP_EMPTY "parse_file: The map is empty"
# define MSG_ATOI_ERROR_LARGE "atoi_check: The digit is larger than INT_MAX"
# define MSG_ATOI_ERROR_SMALL "atoi_check: The digit is smaller than INT_MIN"
# define MSG_ATOI_ERROR_PREFIX_NOT_DIGIT "atoi_check: The prefix of digit \
part is not a digit"
# define MSG_ATOI_ERROR_NOT_DIGIT "atoi_check: Invalid character \
in the digit part"
# define MSG_ATOX_ERROR_PREFIX "atox_check: The prefix of hex number \
is not \"0x\" or \"0X\""
# define MSG_ATOX_ERROR_NOT_HEX "atox_check: Invalid character \
in the hex number"
# define MSG_ATOX_ERROR_LARGE "atox_check: The hex number is larger than \
COLOR_MAX"

typedef struct s_map
{
	int	**data;
	int	**color;
	int	height;
	int	width;
	int	color_flag;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp; // bits per pixel
	int		size_l; // size of a line
	int		endian; // endian
	int		w_width; // window width
	int		w_height; // window height
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		rotate_x;
	int		rotate_y;
	int		rotate_z;
}	t_data;

// param_check.c
void	param_check(int argc, char **argv);

// parse_file.c
void	parse_file(char *filename, t_map *map);

// wrap_file_manip.c
int		open_wrap(char *filename, int flags);
void	close_wrap(int fd);

// wrap_memory.c
void	*malloc_wrap(size_t size);
void	*realloc_wrap(void *ptr, size_t old_size, size_t new_size);
char	**ft_split_wrap(char const *s, char c);

// wrap_mlx.c
void	*mlx_init_wrap(void);
void	*mlx_new_window_wrap(void *mlx_ptr, int width,
			int height, char *title);
void	*mlx_new_image_wrap(void *mlx_ptr, int width, int height);

// free_xd.c
void	free_3d(char ***xd);
void	free_map(t_map *map);

// atoi_check.c
void	atoi_check(const char *str);

// atox_check.c
void	atox_check(const char *str, int i);

// fdf_atoi.c
void	fdf_atoi(const char *str, t_map *map, int i, int j);

// fdf_atox.c
void	fdf_atox(const char *str, t_map *map, int i, int j);

// map_init.c
t_map	*map_init(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_include_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/31 13:40:56 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_INCLUDE_BONUS_H
# define B_INCLUDE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <limits.h>

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
The extension of the file must be \".fdf\" or \".stl\""
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
# define MSG_ATOI_FORMAT_ERROR "atoi_check: The format of the number is wrong"
# define MSG_ATOX_ERROR_PREFIX "atox_check: The prefix of hex number \
is not \"0x\" or \"0X\""
# define MSG_ATOX_ERROR_NOT_HEX "atox_check: Invalid character \
in the hex number"
# define MSG_ATOX_ERROR_LARGE "atox_check: The hex number is larger than \
COLOR_MAX"

# define KEY_ESC 65307
# define WIN_HEIGHT 800
# define WIN_WIDTH 800
# define WIN_TITLE "fdf"
# define IMG_HEIGHT 800
# define IMG_WIDTH 800

# define DEFAULT_COLOR 0x0033FFFF
# define DEFAULT_COLOR_HIGH 0x00FF0000

# define PI 3.14159265358979323846
# define INF 1e9

// Bonus
# define USAGE_TO_DISPLAY "[Usage]\n\
Zoom in/out: m/n\n\
Move: arrow keys\n\
Rotate x-axis: q/w\n\
Rotate y-axis: a/s\n\
Rotate z-axis: z/x\n\
Change view:\n\
  Front view: 1\n\
  Top view: 2\n\
  Right view: 3\n\
  Isometric view: 4\n\
????: o\n\
Exit: ESC\n"

# define KEY_ZOOM_IN 109
# define KEY_ZOOM_OUT 110
# define KEY_MOVE_UP 65362
# define KEY_MOVE_DOWN 65364
# define KEY_MOVE_LEFT 65361
# define KEY_MOVE_RIGHT 65363
# define KEY_ROTATE_X_UP 113
# define KEY_ROTATE_X_DOWN 119
# define KEY_ROTATE_Y_UP 97
# define KEY_ROTATE_Y_DOWN 115
# define KEY_ROTATE_Z_UP 122
# define KEY_ROTATE_Z_DOWN 120
# define KEY_FRONT 49
# define KEY_TOP 50
# define KEY_RIGHT 51
# define KEY_ISOMETRIC 52
# define KEY_QUESTION 111

# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 10
# define ROTATE_ANGLE 1.5

# define STL_FLAG 2
# define STL_FILE_EXTENSION ".stl"
# define STL_FILE_EXTENSION_LEN 4

#endif

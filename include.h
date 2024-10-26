/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:52:15 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:33:55 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

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

#endif
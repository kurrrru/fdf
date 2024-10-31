/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fdf_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/31 13:28:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_FDF_BONUS_H
# define B_FDF_BONUS_H

# include "b_include_bonus.h"
# include "b_map_bonus.h"
# include "b_point_bonus.h"
# include "b_wrap_bonus.h"
# include "b_fdf_math_bonus.h"
# include "bs_stl_bonus.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp;
	int		size_l;
	int		endian;
	double	zoom;
	int		color;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
	t_map	*map;
}	t_data;

// b_fdf_bonus.c
void	fdf(t_map *map);

// b_param_check_bonus.c
int		param_check(int argc, char **argv);

// b_parse_file_bonus.c
void	parse_file(char *filename, t_map *map);

// b_free_xd_bonus.c
void	free_3d(char ***xd);
void	free_2d(char **xd);
void	free_map(t_map *map);

// b_atoi_check_bonus.c
void	atoi_check(const char *str, t_map *map);

// b_atox_check_bonus.c
void	atox_check(const char *str, int i);

// b_fdf_atoi_bonus.c
void	fdf_atoi(const char *str, t_map *map, int i, int j);

// b_fdf_atox_bonus.c
void	fdf_atox(const char *str, t_map *map, int i, int j);

// b_hook_bonus.c
void	hook(t_data *data);

// b_draw_point_bonus.c
void	draw_point(t_data *data, t_point p);

// b_draw_line_bonus.c
void	draw_line(t_data *data, t_point p1, t_point p2);

// b_draw_map_bonus.c
void	draw_map(t_data *data, t_map *map);

// b_isometric_bonus.c
void	isometric(t_data *data, t_map *map);

// b_set_color_bonus.c
void	set_color(t_data *data, t_map *map, int i, int j);
void	small_endian_color(t_point *point);

// b_rotate_bonus.c
void	rotate_x(double pos[3], double angle);
void	rotate_y(double pos[3], double angle);
void	rotate_z(double pos[3], double angle);

// b_shift_center_bonus.c
void	shift_center(t_map *map);

// Bonus
// b_hook_rotate_bonus.c
int		hook_rotate_x(t_data *data, int keycode);
int		hook_rotate_y(t_data *data, int keycode);
int		hook_rotate_z(t_data *data, int keycode);

// b_hook_zoom_bonus.c
int		hook_zoom(t_data *data, int keycode);

// b_hook_move_bonus.c
int		hook_move(t_data *data, int keycode);

// b_hook_color_bonus.c
int		hook_color(t_data *data);
int		hook_color_update(t_data *data);

// b_map_update_bonus.c
void	map_update(t_data *data, t_map *map);

// b_size_adjust_bonus.c
void	size_adjust(t_data *data, t_map *map);

// b_parallel_front_bonus.c
void	front_view(t_data *data, t_map *map);

// b_parallel_top_bonus.c
void	top_view(t_data *data, t_map *map);

// b_parallel_right_bonus.c
void	right_view(t_data *data, t_map *map);

// b_calc_coordinate_bonus.c
void	calc_coordinate(t_data *data, t_map *map, int i, int j);

// b_size_adjust_bonus.c
void	size_adjust(t_data *data, t_map *map);

// b_key_hook_loop_bonus.c
int		key_hook_loop(int keycode, t_data *data);

// b_is_crossing_bonus.c
int		is_crossing(t_point p1, t_point p2, t_point v1, t_point v2);
void	point_init(t_point *v1, t_point *v2, t_point *v3, t_point *v4);

#endif

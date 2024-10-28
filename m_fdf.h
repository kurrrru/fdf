/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fdf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:36:22 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_FDF_H
# define M_FDF_H

# include "m_include.h"
# include "m_map.h"
# include "m_point.h"
# include "m_wrap.h"
# include "m_fdf_math.h"

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
	double	shift_x;
	double	shift_y;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
}	t_data;

void	fdf(t_map *map);

// m_param_check.c
void	param_check(int argc, char **argv);

// m_parse_file.c
void	parse_file(char *filename, t_map *map);

// m_free_xd.c
void	free_3d(char ***xd);
void	free_map(t_map *map);

// m_atoi_check.c
void	atoi_check(const char *str, t_map *map);

// m_atox_check.c
void	atox_check(const char *str, int i);

// m_fdf_atoi.c
void	fdf_atoi(const char *str, t_map *map, int i, int j);

// m_fdf_atox.c
void	fdf_atox(const char *str, t_map *map, int i, int j);

// m_hook.c
void	hook_close(t_data *data);

// m_draw_point.c
void	draw_point(t_data *data, t_point p);

// m_draw_line.c
void	draw_line(t_data *data, t_point p1, t_point p2);

// m_draw_map.c
void	draw_map(t_data *data, t_map *map);

// m_isometric.c
void	isometric(t_data *data, t_map *map);

// m_isometric_subfunc.c
void	isometric_init(t_data *data);
void	small_endian_color(t_point *point);
void	set_color(t_data *data, t_map *map, int i, int j);

// m_rotate.c
void	rotate_x(double pos[3], double angle);
void	rotate_y(double pos[3], double angle);
void	rotate_z(double pos[3], double angle);

// m_shift_center.c
void	shift_center(t_data *data, t_map *map);

#endif

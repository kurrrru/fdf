/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:24:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 14:57:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "include.h"
# include "map.h"
# include "point.h"
# include "wrap.h"
# include "fdf_math.h"

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	int		*addr;
	int		bpp; // bits per pixel
	int		size_l; // size of a line
	int		endian; // endian
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	double	rotate_x;
	double	rotate_y;
	double	rotate_z;
}	t_data;

void	fdf(t_map *map);

// param_check.c
void	param_check(int argc, char **argv);

// parse_file.c
void	parse_file(char *filename, t_map *map);

// free_xd.c
void	free_3d(char ***xd);
void	free_map(t_map *map);

// atoi_check.c
void	atoi_check(const char *str, t_map *map);

// atox_check.c
void	atox_check(const char *str, int i);

// fdf_atoi.c
void	fdf_atoi(const char *str, t_map *map, int i, int j);

// fdf_atox.c
void	fdf_atox(const char *str, t_map *map, int i, int j);

// hook.c
void	hook_close(t_data *data);

// draw_point.c
void	draw_point(t_data *data, t_point p);

// draw_line.c
void	draw_line(t_data *data, t_point p1, t_point p2);

// draw_map.c
void	draw_map(t_data *data, t_map *map);

// isometric.c
void	isometric(t_data *data, t_map *map);

// rotate.c
void	rotate_x(double pos[3], double angle);
void	rotate_y(double pos[3], double angle);
void	rotate_z(double pos[3], double angle);

#endif

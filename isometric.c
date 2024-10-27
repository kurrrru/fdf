/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:22:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 22:43:51 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_coordinate(t_data *data, t_map *map, int i, int j);
static void	size_adjust(t_data *data, t_map *map);
static void	update_zoom(t_data *data, t_map *map);
static void	update_size(t_data *data, t_map *map);

void	isometric(t_data *data, t_map *map)
{
	int	i;
	int	j;

	isometric_init(data);
	map->points = malloc_wrap(sizeof(t_point *) * map->height);
	i = -1;
	while (++i < map->height)
	{
		map->points[i] = malloc_wrap(sizeof(t_point) * map->width);
		j = -1;
		while (++j < map->width)
		{
			calc_coordinate(data, map, i, j);
			if (map->color_flag)
				map->points[i][j].color.num = map->color[i][j];
			else
				set_color(data, map, i, j);
		}
	}
	size_adjust(data, map);
	shift_center(data, map);
}

static void	calc_coordinate(t_data *data, t_map *map, int i, int j)
{
	double	pos[3];

	pos[0] = j;
	pos[1] = i;
	pos[2] = map->data[i][j];
	rotate_z(pos, data->rotate_z);
	rotate_y(pos, data->rotate_y);
	rotate_x(pos, data->rotate_x);
	map->points[i][j].x = pos[0] * data->zoom;
	map->points[i][j].y = pos[1] * data->zoom;
}

static void	size_adjust(t_data *data, t_map *map)
{
	int	i;
	int	j;

	map->x_max = -INF;
	map->x_min = INF;
	map->y_max = -INF;
	map->y_min = INF;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->x_max = fdf_max_d(map->x_max, map->points[i][j].x);
			map->x_min = fdf_min_d(map->x_min, map->points[i][j].x);
			map->y_max = fdf_max_d(map->y_max, map->points[i][j].y);
			map->y_min = fdf_min_d(map->y_min, map->points[i][j].y);
		}
	}
	update_zoom(data, map);
	update_size(data, map);
}

static void	update_zoom(t_data *data, t_map *map)
{
	if (map->x_max - map->x_min == 0 && map->y_max - map->y_min == 0)
		data->zoom = 1;
	else if (map->x_max - map->x_min == 0)
		data->zoom = WIN_HEIGHT * 0.8 / (map->y_max - map->y_min);
	else if (map->y_max - map->y_min == 0)
		data->zoom = WIN_WIDTH * 0.8 / (map->x_max - map->x_min);
	else
		data->zoom = fdf_min_d(WIN_WIDTH * 0.8 / (map->x_max - map->x_min),
				WIN_HEIGHT * 0.8 / (map->y_max - map->y_min));
}

static void	update_size(t_data *data, t_map *map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x = (map->points[i][j].x - data->shift_x)
				* data->zoom + data->shift_x;
			map->points[i][j].y = (map->points[i][j].y - data->shift_y)
				* data->zoom + data->shift_y;
		}
	}
}

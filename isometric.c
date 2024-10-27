/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:22:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 15:46:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_coordinate(t_data *data, t_map *map, int i, int j);
static void	shift_center(t_data *data, t_map *map);

void	isometric(t_data *data, t_map *map)
{
	int	i;
	int	j;
	int tmp;

	data->rotate_x = -35.264 * PI / 180;
	data->rotate_y = 0;
	data->rotate_z = -45 * PI / 180;
	data->zoom = fdf_max(fdf_min(WIN_WIDTH / map->width / 2, WIN_HEIGHT / map->height / 2), 1);
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
			{
				map->points[i][j].color.trgb[0] = in_div(0x00, 0x00, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[1] = in_div(0xFF, 0x00, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[2] = in_div(0xFF, 0x70, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[3] = in_div(0xFF, 0x00, map->data[i][j] - map->min, map->max - map->min);
				if (data->endian == 0)
				{
					tmp = map->points[i][j].color.trgb[0];
					map->points[i][j].color.trgb[0] = map->points[i][j].color.trgb[3];
					map->points[i][j].color.trgb[3] = tmp;
					tmp = map->points[i][j].color.trgb[1];
					map->points[i][j].color.trgb[1] = map->points[i][j].color.trgb[2];
					map->points[i][j].color.trgb[2] = tmp;
				}
			}
		}
	}
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

static void	shift_center(t_data *data, t_map *map)
{
	int	i;
	int	j;
	int	x_center;
	int	y_center;

	x_center = 0;
	y_center = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			x_center += map->points[i][j].x;
			y_center += map->points[i][j].y;
		}
	}
	x_center /= map->height * map->width;
	y_center /= map->height * map->width;
	data->shift_x = WIN_WIDTH / 2 - x_center;
	data->shift_y = WIN_HEIGHT / 2 - y_center;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x += data->shift_x;
			map->points[i][j].y += data->shift_y;
		}
	}
}
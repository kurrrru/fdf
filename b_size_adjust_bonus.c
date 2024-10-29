/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_size_adjust_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:46:37 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 19:47:06 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static void	update_zoom(t_data *data, t_map *map);
static void	update_size(t_data *data, t_map *map);

void	size_adjust(t_data *data, t_map *map)
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
			map->points[i][j].x = map->points[i][j].x * data->zoom;
			map->points[i][j].y = map->points[i][j].y * data->zoom;
			map->points[i][j].z = map->points[i][j].z * data->zoom;
		}
	}
	map->x_max = map->x_max * data->zoom;
	map->x_min = map->x_min * data->zoom;
	map->y_max = map->y_max * data->zoom;
	map->y_min = map->y_min * data->zoom;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:22:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 22:35:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	find_max_min(t_map *map);

void	isometric(t_data *data, t_map *map)
{
	int	i;
	int	j;

	data->rotate_x = 30;
	data->rotate_y = 30;
	data->rotate_z = 0;
	data->zoom = fdf_min(WIN_WIDTH / map->width / 2, WIN_HEIGHT / map->height / 2);
	map->points = malloc_wrap(sizeof(t_point *) * map->height);
	int x_ori = 300;
	int y_ori = 300;
	find_max_min(map);
	i = -1;
	while (++i < map->height)
	{
		map->points[i] = malloc_wrap(sizeof(t_point) * map->width);
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x = x_ori + ((j - i) * cos(30 * PI / 180)) * data->zoom;
			map->points[i][j].y = y_ori + ((j + i) * sin(30 * PI / 180) - map->data[i][j] / 3) * data->zoom;
			if (map->color_flag)
				map->points[i][j].color.num = map->color[i][j];
			else
			{
				map->points[i][j].color.trgb[0] = in_div(0xFF, 0x40, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[1] = in_div(0xFF, 0x40, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[2] = in_div(0xFF, 0x70, map->data[i][j] - map->min, map->max - map->min);
				map->points[i][j].color.trgb[3] = in_div(0x00, 0x00, map->data[i][j] - map->min, map->max - map->min);
			}
		}
	}
}

static void	find_max_min(t_map *map)
{
	int	i;
	int	j;

	map->max = INT_MIN;
	map->min = INT_MAX;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->max = fdf_max(map->max, map->data[i][j]);
			map->min = fdf_min(map->min, map->data[i][j]);
		}
	}
}

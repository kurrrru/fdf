/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:22:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 01:42:09 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_data *data, t_map *map)
{
	int	i;
	int	j;
	int tmp;

	data->rotate_x = 30;
	data->rotate_y = 30;
	data->rotate_z = 0;
	data->zoom = fdf_max(fdf_min(WIN_WIDTH / map->width / 2, WIN_HEIGHT / map->height / 2), 1);
	map->points = malloc_wrap(sizeof(t_point *) * map->height);
	int x_ori = (WIN_WIDTH / 4 * map->width + WIN_WIDTH * 3 / 4 * map->height) / (map->width + map->height);
	int y_ori = WIN_HEIGHT / 4;
	i = -1;
	while (++i < map->height)
	{
		map->points[i] = malloc_wrap(sizeof(t_point) * map->width);
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x = x_ori + ((j - i) * cos(30 * PI / 180)) * data->zoom;
			map->points[i][j].y = y_ori + ((j + i) * sin(30 * PI / 180) - map->data[i][j] / 5) * data->zoom;
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
}

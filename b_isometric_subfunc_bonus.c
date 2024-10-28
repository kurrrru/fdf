/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_isometric_subfunc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:42 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:20:42 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

void	isometric_init(t_data *data)
{
	data->rotate_x = -acos(1 / sqrt(3));
	data->rotate_y = 0;
	data->rotate_z = -45 * PI / 180;
	data->zoom = 1;
	data->shift_x = 0;
	data->shift_y = 0;
}

void	small_endian_color(t_point *point)
{
	int	tmp;

	tmp = point->color.trgb[0];
	point->color.trgb[0] = point->color.trgb[3];
	point->color.trgb[3] = tmp;
	tmp = point->color.trgb[1];
	point->color.trgb[1] = point->color.trgb[2];
	point->color.trgb[2] = tmp;
}

void	set_color(t_data *data, t_map *map, int i, int j)
{
	map->points[i][j].color.trgb[0] = in_div(0x00, 0x00,
			map->data[i][j] - map->z_min, map->z_max - map->z_min);
	map->points[i][j].color.trgb[1] = in_div(0xFF, 0x00,
			map->data[i][j] - map->z_min, map->z_max - map->z_min);
	map->points[i][j].color.trgb[2] = in_div(0xFF, 0x70,
			map->data[i][j] - map->z_min, map->z_max - map->z_min);
	map->points[i][j].color.trgb[3] = in_div(0xFF, 0x00,
			map->data[i][j] - map->z_min, map->z_max - map->z_min);
	if (data->endian == 0)
		small_endian_color(&map->points[i][j]);
}

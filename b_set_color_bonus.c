/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_set_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:48:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 19:53:35 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static void	small_endian_color(t_point *point);

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

static void	small_endian_color(t_point *point)
{
	int	tmp;

	tmp = point->color.trgb[0];
	point->color.trgb[0] = point->color.trgb[3];
	point->color.trgb[3] = tmp;
	tmp = point->color.trgb[1];
	point->color.trgb[1] = point->color.trgb[2];
	point->color.trgb[2] = tmp;
}

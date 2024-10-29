/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_parallel_top_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:56:03 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:13:16 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static void	top_init(t_data *data);

void	top_view(t_data *data, t_map *map)
{
	int	i;
	int	j;

	top_init(data);
	if (map->points == NULL)
		map->points = malloc_wrap(sizeof(t_point *) * map->height);
	i = -1;
	while (++i < map->height)
	{
		if (map->points[i] == NULL)
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
	shift_center(map);
}

static void	top_init(t_data *data)
{
	data->rotate_x = 0;
	data->rotate_y = 0;
	data->rotate_z = 0;
}

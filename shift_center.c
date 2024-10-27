/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_center.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:15:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 22:28:35 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	calc_center(t_map *map, double *x_center, double *y_center);

void	shift_center(t_data *data, t_map *map)
{
	int		i;
	int		j;
	double	x_center;
	double	y_center;

	calc_center(map, &x_center, &y_center);
	data->shift_x += WIN_WIDTH / 2 - x_center;
	data->shift_y += WIN_HEIGHT / 2 - y_center;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			map->points[i][j].x += WIN_WIDTH / 2 - x_center;
			map->points[i][j].y += WIN_HEIGHT / 2 - y_center;
		}
	}
}

static void	calc_center(t_map *map, double *x_center, double *y_center)
{
	int		i;
	int		j;

	*x_center = 0;
	*y_center = 0;
	i = -1;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			*x_center += map->points[i][j].x;
			*y_center += map->points[i][j].y;
		}
	}
	*x_center /= map->height * map->width;
	*y_center /= map->height * map->width;
}

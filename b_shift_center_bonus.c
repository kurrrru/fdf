/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_shift_center_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:15:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 18:29:56 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static void	calc_center(t_map *map, double *x_center, double *y_center);

void	shift_center(t_data *data, t_map *map)
{
	int		i;
	int		j;
	double	x_center;
	double	y_center;

	calc_center(map, &x_center, &y_center);
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
	(void)data;
}

static void	calc_center(t_map *map, double *x_center, double *y_center)
{
	*x_center = (map->x_max + map->x_min) / 2;
	*y_center = (map->y_max + map->y_min) / 2;
}

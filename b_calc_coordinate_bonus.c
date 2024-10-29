/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_calc_coordinate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:49:03 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 19:49:07 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

void	calc_coordinate(t_data *data, t_map *map, int i, int j)
{
	double	pos[3];

	pos[0] = j;
	pos[1] = i;
	pos[2] = map->data[i][j];
	rotate_z(pos, data->rotate_z);
	rotate_y(pos, data->rotate_y);
	rotate_x(pos, data->rotate_x);
	map->points[i][j].x = pos[0];
	map->points[i][j].y = pos[1];
	map->points[i][j].z = pos[2];
}

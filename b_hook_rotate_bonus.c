/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:43:56 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 01:05:23 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	hook_rotate_x(t_data *data, int keycode)
{
	double	angle;
	int		i;
	int		j;
	double	pos[3];

	if (keycode == KEY_ROTATE_X_UP)
		angle = ROTATE_ANGLE;
	else if (keycode == KEY_ROTATE_X_DOWN)
		angle = -ROTATE_ANGLE;
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			pos[0] = data->map->points[i][j].x - data->shift_x;
			pos[1] = data->map->points[i][j].y - data->shift_y;
			pos[2] = data->map->points[i][j].z;
			rotate_x(pos, angle);
			data->map->points[i][j].x = pos[0] + data->shift_x;
			data->map->points[i][j].y = pos[1] + data->shift_y;
			data->map->points[i][j].z = pos[2];
		}
	}
	map_update(data, data->map);
	return (0);
}

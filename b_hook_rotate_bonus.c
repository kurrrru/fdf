/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_rotate_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:43:56 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 18:45:46 by nkawaguc         ###   ########.fr       */
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
			pos[0] = data->map->points[i][j].x - WIN_WIDTH / 2;
			pos[1] = data->map->points[i][j].y - WIN_HEIGHT / 2;
			pos[2] = data->map->points[i][j].z;
			rotate_x(pos, angle);
			data->map->points[i][j].x = pos[0] + WIN_WIDTH / 2;
			data->map->points[i][j].y = pos[1] + WIN_HEIGHT / 2;
			data->map->points[i][j].z = pos[2];
		}
	}
	return (0);
}

int	hook_rotate_y(t_data *data, int keycode)
{
	double	angle;
	int		i;
	int		j;
	double	pos[3];

	if (keycode == KEY_ROTATE_Y_UP)
		angle = ROTATE_ANGLE;
	else if (keycode == KEY_ROTATE_Y_DOWN)
		angle = -ROTATE_ANGLE;
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			pos[0] = data->map->points[i][j].x - WIN_WIDTH / 2;
			pos[1] = data->map->points[i][j].y - WIN_HEIGHT / 2;
			pos[2] = data->map->points[i][j].z;
			rotate_y(pos, angle);
			data->map->points[i][j].x = pos[0] + WIN_WIDTH / 2;
			data->map->points[i][j].y = pos[1] + WIN_HEIGHT / 2;
			data->map->points[i][j].z = pos[2];
		}
	}
	return (0);
}

int	hook_rotate_z(t_data *data, int keycode)
{
	double	angle;
	int		i;
	int		j;
	double	pos[3];

	if (keycode == KEY_ROTATE_Z_UP)
		angle = ROTATE_ANGLE;
	else if (keycode == KEY_ROTATE_Z_DOWN)
		angle = -ROTATE_ANGLE;
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			pos[0] = data->map->points[i][j].x - WIN_WIDTH / 2;
			pos[1] = data->map->points[i][j].y - WIN_HEIGHT / 2;
			pos[2] = data->map->points[i][j].z;
			rotate_z(pos, angle);
			data->map->points[i][j].x = pos[0] + WIN_WIDTH / 2;
			data->map->points[i][j].y = pos[1] + WIN_HEIGHT / 2;
			data->map->points[i][j].z = pos[2];
		}
	}
	return (0);
}

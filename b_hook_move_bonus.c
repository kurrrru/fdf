/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:51:13 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 18:51:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	hook_move(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			if (keycode == KEY_MOVE_UP)
				data->map->points[i][j].y -= MOVE_FACTOR;
			else if (keycode == KEY_MOVE_DOWN)
				data->map->points[i][j].y += MOVE_FACTOR;
			else if (keycode == KEY_MOVE_LEFT)
				data->map->points[i][j].x -= MOVE_FACTOR;
			else if (keycode == KEY_MOVE_RIGHT)
				data->map->points[i][j].x += MOVE_FACTOR;
		}
	}
	return (0);
}

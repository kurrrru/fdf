/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_zoom_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:49:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/17 22:26:36 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	hook_zoom(t_data *data, int keycode)
{
	double	zoom;
	int		i;
	int		j;

	if (keycode == KEY_ZOOM_IN)
		zoom = ZOOM_FACTOR;
	else
		zoom = 1 / ZOOM_FACTOR;
	i = -1;
	while (++i < data->map->height)
	{
		j = -1;
		while (++j < data->map->width)
		{
			data->map->points[i][j].x = (data->map->points[i][j].x
					- WIN_WIDTH / 2) * zoom + WIN_WIDTH / 2;
			data->map->points[i][j].y = (data->map->points[i][j].y
					- WIN_HEIGHT / 2) * zoom + WIN_HEIGHT / 2;
		}
	}
	return (0);
}

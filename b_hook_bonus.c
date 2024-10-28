/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:19:07 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static int	key_hook(int keycode, t_data *data);
static int	hook_esc(t_data *data);
static int	cross_hook(t_data *data);

void	hook(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, 17, 0, cross_hook, data);
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		return (hook_esc(data));
	else if (keycode == KEY_ROTATE_X_UP || keycode == KEY_ROTATE_X_DOWN)
		return (hook_rotate_x(data, keycode));
	// else if (keycode == KEY_ROTATE_Y_UP || keycode == KEY_ROTATE_Y_DOWN)
	// 	return (hook_rotate_y(data, keycode));
	// else if (keycode == KEY_ROTATE_Z_UP || keycode == KEY_ROTATE_Z_DOWN)
	// 	return (hook_rotate_z(data, keycode));
	// else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
	// 	return (hook_zoom(data, keycode));
	// else if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN
	// 	|| keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
	// 	return (hook_move(data, keycode));
	// else if (keycode == KEY_QUESTION)
	// 	return (hook_color(data));
	return (0);
}

static int	hook_esc(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	return (0);
}

static int	cross_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	return (0);
}

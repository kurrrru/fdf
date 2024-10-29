/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 19:45:46 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static int	key_hook(int keycode, t_data *data);
static int	hook_esc(t_data *data);
static int	cross_hook(t_data *data);
static int	loop_hook(t_data *data);

static int key_hook2(int keycode, t_data *data)
{
	if (keycode == KEY_ROTATE_X_UP || keycode == KEY_ROTATE_X_DOWN)
		return (hook_rotate_x(data, keycode));
	else if (keycode == KEY_ROTATE_Y_UP || keycode == KEY_ROTATE_Y_DOWN)
		return (hook_rotate_y(data, keycode));
	else if (keycode == KEY_ROTATE_Z_UP || keycode == KEY_ROTATE_Z_DOWN)
		return (hook_rotate_z(data, keycode));
	else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		return (hook_zoom(data, keycode));
	else if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN
		|| keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
		return (hook_move(data, keycode));
	else if (keycode == KEY_QUESTION)
		return (hook_color(data));
	return (0);
}

void	hook(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, DestroyNotify, 0, cross_hook, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_hook2, data); // 2: key press 0: key release
	mlx_loop_hook(data->mlx, loop_hook, data);
}

static int	key_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		return (hook_esc(data));
	if (keycode == KEY_ISOMETRIC)
	{
		isometric(data, data->map);
		return (0);
	}
	if (keycode == KEY_FRONT)
	{
		front_view(data, data->map);
		return (0);
	}
	if (keycode == KEY_TOP)
	{
		top_view(data, data->map);
		return (0);
	}
	if (keycode == KEY_RIGHT)
	{
		right_view(data, data->map);
		return (0);
	}
	return (0);
}

static int	hook_esc(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	data->win = NULL;
	return (0);
}

static int	cross_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	data->win = NULL;
	return (0);
}

static int	loop_hook(t_data *data)
{
	(void)data;
	if (data->win != NULL)
	{
		map_update(data, data->map);
		hook_color_update(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

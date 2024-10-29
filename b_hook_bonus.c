/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:19:50 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static int	key_hook(int keycode, t_data *data);
static int	hook_esc(t_data *data);
static int	cross_hook(t_data *data);
static int	loop_hook(t_data *data);

void	hook(t_data *data)
{
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, DestroyNotify, 0, cross_hook, data);
	mlx_hook(data->win, KeyPress, KeyPressMask, key_hook_loop, data);
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
	if (data->win != NULL)
	{
		map_update(data, data->map);
		hook_color_update(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	}
	return (0);
}

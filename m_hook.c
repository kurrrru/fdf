/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_hook.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:59 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:19:59 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

static int	esc_hook(int keycode, t_data *data);
static int	cross_hook(t_data *data);

void	hook_close(t_data *data)
{
	mlx_key_hook(data->win, esc_hook, data);
	mlx_hook(data->win, 17, 0, cross_hook, data);
}

static int	esc_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->img);
		mlx_destroy_window(data->mlx, data->win);
		mlx_loop_end(data->mlx);
	}
	return (0);
}

static int	cross_hook(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	return (0);
}

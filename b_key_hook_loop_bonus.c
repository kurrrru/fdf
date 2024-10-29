/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_key_hook_loop_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:20:08 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:20:12 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	key_hook_loop(int keycode, t_data *data)
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

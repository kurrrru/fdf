/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_key_hook_loop_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:27:01 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:50:45 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

int	stl_key_hook_loop(int keycode, t_stldata *stldata)
{
	if (keycode == KEY_ROTATE_X_UP || keycode == KEY_ROTATE_X_DOWN)
		return (stl_hook_rotate_x(stldata, keycode));
	else if (keycode == KEY_ROTATE_Y_UP || keycode == KEY_ROTATE_Y_DOWN)
		return (stl_hook_rotate_y(stldata, keycode));
	else if (keycode == KEY_ROTATE_Z_UP || keycode == KEY_ROTATE_Z_DOWN)
		return (stl_hook_rotate_z(stldata, keycode));
	else if (keycode == KEY_ZOOM_IN || keycode == KEY_ZOOM_OUT)
		return (stl_hook_zoom(stldata, keycode));
	else if (keycode == KEY_MOVE_UP || keycode == KEY_MOVE_DOWN
		|| keycode == KEY_MOVE_LEFT || keycode == KEY_MOVE_RIGHT)
		return (stl_hook_move(stldata, keycode));
	return (0);
}

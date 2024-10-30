/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_hook_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:23:49 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:50:31 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

int	stl_hook_rotate_x(t_stldata *stldata, int keycode)
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
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			pos[0] = stldata->tris[i].p[j].x;
			pos[1] = stldata->tris[i].p[j].y - WIN_HEIGHT / 2;
			pos[2] = stldata->tris[i].p[j].z - WIN_WIDTH / 2;
			rotate_x(pos, angle);
			stldata->tris[i].p[j].x = pos[0];
			stldata->tris[i].p[j].y = pos[1] + WIN_HEIGHT / 2;
			stldata->tris[i].p[j].z = pos[2] + WIN_WIDTH / 2;
		}
	}
	return (0);
}

int	stl_hook_rotate_y(t_stldata *stldata, int keycode)
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
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			pos[0] = stldata->tris[i].p[j].x - WIN_WIDTH / 2;
			pos[1] = stldata->tris[i].p[j].y;
			pos[2] = stldata->tris[i].p[j].z - WIN_HEIGHT / 2;
			rotate_y(pos, angle);
			stldata->tris[i].p[j].x = pos[0] + WIN_WIDTH / 2;
			stldata->tris[i].p[j].y = pos[1];
			stldata->tris[i].p[j].z = pos[2] + WIN_HEIGHT / 2;
		}
	}
	return (0);
}

int	stl_hook_rotate_z(t_stldata *stldata, int keycode)
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
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			pos[0] = stldata->tris[i].p[j].x - WIN_WIDTH / 2;
			pos[1] = stldata->tris[i].p[j].y - WIN_HEIGHT / 2;
			pos[2] = stldata->tris[i].p[j].z;
			rotate_z(pos, angle);
			stldata->tris[i].p[j].x = pos[0] + WIN_WIDTH / 2;
			stldata->tris[i].p[j].y = pos[1] + WIN_HEIGHT / 2;
			stldata->tris[i].p[j].z = pos[2];
		}
	}
	return (0);
}

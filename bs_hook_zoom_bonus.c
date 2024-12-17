/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_hook_zoom_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:28:08 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/12/17 22:27:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

int	stl_hook_zoom(t_stldata *stldata, int keycode)
{
	double	zoom;
	int		i;
	int		j;

	if (keycode == KEY_ZOOM_IN)
		zoom = ZOOM_FACTOR;
	else
		zoom = 1 / ZOOM_FACTOR;
	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			stldata->tris[i].p[j].x = (stldata->tris[i].p[j].x
					- WIN_WIDTH / 2) * zoom + WIN_WIDTH / 2;
			stldata->tris[i].p[j].y = (stldata->tris[i].p[j].y
					- WIN_HEIGHT / 2) * zoom + WIN_HEIGHT / 2;
			stldata->tris[i].p[j].z *= zoom;
		}
	}
	return (0);
}

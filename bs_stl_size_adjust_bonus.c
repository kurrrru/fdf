/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_size_adjust_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:58:30 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:06:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static void	stl_update_zoom(t_stldata *stldata);

void	stl_size_adjust(t_stldata *stldata)
{
	int	i;
	int	j;

	stl_update_zoom(stldata);
	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			stldata->tris[i].p[j].x *= stldata->zoom;
			stldata->tris[i].p[j].y *= stldata->zoom;
			stldata->tris[i].p[j].z *= stldata->zoom;
		}
	}
	stldata->x_max *= stldata->zoom;
	stldata->x_min *= stldata->zoom;
	stldata->y_max *= stldata->zoom;
	stldata->y_min *= stldata->zoom;
}

static void	stl_update_zoom(t_stldata *stldata)
{
	if (stldata->x_max == stldata->x_min && stldata->y_max == stldata->y_min)
		stldata->zoom = 1;
	else if (stldata->x_max == stldata->x_min)
		stldata->zoom = WIN_HEIGHT * 0.8 / (stldata->y_max - stldata->y_min);
	else if (stldata->y_max == stldata->y_min)
		stldata->zoom = WIN_WIDTH * 0.8 / (stldata->x_max - stldata->x_min);
	else
		stldata->zoom
			= fdf_min(WIN_WIDTH * 0.8 / (stldata->x_max - stldata->x_min),
				WIN_HEIGHT * 0.8 / (stldata->y_max - stldata->y_min));
}

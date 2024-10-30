/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_hook_move_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 21:29:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:29:33 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

int	stl_hook_move(t_stldata *stldata, int keycode)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			if (keycode == KEY_MOVE_UP)
				stldata->tris[i].p[j].y -= MOVE_FACTOR;
			else if (keycode == KEY_MOVE_DOWN)
				stldata->tris[i].p[j].y += MOVE_FACTOR;
			else if (keycode == KEY_MOVE_LEFT)
				stldata->tris[i].p[j].x -= MOVE_FACTOR;
			else if (keycode == KEY_MOVE_RIGHT)
				stldata->tris[i].p[j].x += MOVE_FACTOR;
		}
	}
	return (0);
}

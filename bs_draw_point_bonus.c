/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_draw_point_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:07:36 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 18:02:43 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

void	stl_draw_point(t_stldata *stldata, t_point p)
{
	int		color;
	int		*addr;

	// printf("x=%f, y=%f, z=%f\n", p.x, p.y, p.z);
	if (p.x < 0 || p.x >= WIN_WIDTH || p.y < 0 || p.y >= WIN_HEIGHT)
		return ;
	printf("x=%f, y=%f, z=%f, color=%x\n", p.x, p.y, p.z, p.color.num);
	addr = stldata->addr + (int)p.y * WIN_WIDTH + (int)p.x;
	color = p.color.num;
	if (p.z < stldata->z_buffer[(int)p.y * WIN_WIDTH + (int)p.x])
	{
		*addr = color;
		stldata->z_buffer[(int)p.y * WIN_WIDTH + (int)p.x] = p.z;
	}
}
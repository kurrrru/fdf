/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_draw_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:23 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:24:21 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

#include <stdio.h>

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	int		step;
	int		i;
	t_point	p;

	step = fdf_max(fdf_abs(p2.x - p1.x), fdf_abs(p2.y - p1.y));
	i = -1;
	while (i <= step)
	{
		p.x = in_div_d(p1.x, p2.x, i, step);
		p.y = in_div_d(p1.y, p2.y, i, step);
		p.color.trgb[0] = in_div(p1.color.trgb[0], p2.color.trgb[0], i, step);
		p.color.trgb[1] = in_div(p1.color.trgb[1], p2.color.trgb[1], i, step);
		p.color.trgb[2] = in_div(p1.color.trgb[2], p2.color.trgb[2], i, step);
		p.color.trgb[3] = in_div(p1.color.trgb[3], p2.color.trgb[3], i, step);
		draw_point(data, p);
		i++;
	}
}

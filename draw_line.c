/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:22 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:44:27 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	int		step;
	int		i;
	t_point	p;

	step = fdf_max(fdf_abs(p2.x - p1.x), fdf_abs(p2.y - p1.y));
	i = -1;
	printf("p1.x = %d, p1.y = %d, p2.x = %d, p2.y = %d\n", p1.x, p1.y, p2.x, p2.y);
	printf("step = %d\n", step);
	while (i <= step)
	{
		p.x = fdf_in_div(p1.x, p2.x, i, step);
		p.y = fdf_in_div(p1.y, p2.y, i, step);
		p.color.trgb.t = 0;
		p.color.trgb.r = fdf_in_div(p1.color.trgb.r, p2.color.trgb.r, i, step);
		p.color.trgb.g = fdf_in_div(p1.color.trgb.g, p2.color.trgb.g, i, step);
		p.color.trgb.b = fdf_in_div(p1.color.trgb.b, p2.color.trgb.b, i, step);
		draw_point(data, p);
		printf("x = %d, y = %d, [%d, %d, %d, %d]\n", p.x, p.y, p.color.trgb.t, p.color.trgb.r, p.color.trgb.g, p.color.trgb.b);
		i++;
	}
}

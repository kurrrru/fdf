/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:22 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 21:14:33 by nkawaguc         ###   ########.fr       */
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
		p.x = in_div(p1.x, p2.x, i, step);
		p.y = in_div(p1.y, p2.y, i, step);
		p.color.trgb[0] = in_div(p1.color.trgb[0], p2.color.trgb[0], i, step);
		p.color.trgb[1] = in_div(p1.color.trgb[1], p2.color.trgb[1], i, step);
		p.color.trgb[2] = in_div(p1.color.trgb[2], p2.color.trgb[2], i, step);
		p.color.trgb[3] = in_div(p1.color.trgb[3], p2.color.trgb[3], i, step);
		draw_point(data, p);
		printf("x = %d, y = %d, [%d, %d, %d, %d]\n", p.x, p.y, p.color.trgb[0], p.color.trgb[1], p.color.trgb[2], p.color.trgb[3]);
		i++;
	}
}

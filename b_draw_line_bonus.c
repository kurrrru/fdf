/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_draw_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:23 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:05:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

#include <stdio.h>

static int	is_needed_to_draw(t_point p1, t_point p2);
static void	point_init(t_point *v1, t_point *v2, t_point *v3, t_point *v4);
static int	is_crossing(t_point p1, t_point p2, t_point v1, t_point v2);

void	draw_line(t_data *data, t_point p1, t_point p2)
{
	int		step;
	int		i;
	t_point	p;

	if (is_needed_to_draw(p1, p2) == FALSE)
		return ;
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

static int	is_needed_to_draw(t_point p1, t_point p2)
{
	t_point	v1;
	t_point	v2;
	t_point	v3;
	t_point	v4;

	point_init(&v1, &v2, &v3, &v4);
	if (p1.x >= 0 && p1.x < WIN_WIDTH && p1.y >= 0 && p1.y < WIN_HEIGHT)
		return (TRUE);
	if (p2.x >= 0 && p2.x < WIN_WIDTH && p2.y >= 0 && p2.y < WIN_HEIGHT)
		return (TRUE);
	if (is_crossing(p1, p2, v1, v2) == TRUE)
		return (TRUE);
	if (is_crossing(p1, p2, v1, v3) == TRUE)
		return (TRUE);
	if (is_crossing(p1, p2, v2, v4) == TRUE)
		return (TRUE);
	if (is_crossing(p1, p2, v3, v4) == TRUE)
		return (TRUE);
	return (FALSE);
}

static void	point_init(t_point *v1, t_point *v2, t_point *v3, t_point *v4)
{
	v1->x = 0;
	v1->y = 0;
	v2->x = WIN_WIDTH;
	v2->y = 0;
	v3->x = 0;
	v3->y = WIN_HEIGHT;
	v4->x = WIN_WIDTH;
	v4->y = WIN_HEIGHT;
}

static int	is_crossing(t_point p1, t_point p2, t_point v1, t_point v2)
{
	double	d1;
	double	d2;
	double	d3;
	double	d4;

	d1 = (v2.x - v1.x) * (p1.y - v1.y) - (v2.y - v1.y) * (p1.x - v1.x);
	d2 = (v2.x - v1.x) * (p2.y - v1.y) - (v2.y - v1.y) * (p2.x - v1.x);
	d3 = (p2.x - p1.x) * (v1.y - p1.y) - (p2.y - p1.y) * (v1.x - p1.x);
	d4 = (p2.x - p1.x) * (v2.y - p1.y) - (p2.y - p1.y) * (v2.x - p1.x);
	if (d1 * d2 < 0 && d3 * d4 < 0)
		return (TRUE);
	return (FALSE);
}

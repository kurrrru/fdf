/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_need_to_draw_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:12:12 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/31 13:36:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static double	area(t_point p1, t_point p2, t_point p3);
static int		in_triangle(t_tri *tri, t_point p);
static int		any_is_crossing(t_point p1, t_point p2);
static int		any_in_window(t_tri *tri);

int	stl_is_needed_to_draw(t_tri *tri)
{
	if (any_in_window(tri))
		return (TRUE);
	if (in_triangle(tri, (t_point){0, 0, 0, {0}}))
		return (TRUE);
	if (in_triangle(tri, (t_point){WIN_WIDTH - 1, 0, 0, {0}}))
		return (TRUE);
	if (in_triangle(tri, (t_point){0, WIN_HEIGHT - 1, 0, {0}}))
		return (TRUE);
	if (in_triangle(tri, (t_point){WIN_WIDTH - 1, WIN_HEIGHT - 1, 0, {0}}))
		return (TRUE);
	if (any_is_crossing(tri->p[0], tri->p[1]))
		return (TRUE);
	if (any_is_crossing(tri->p[0], tri->p[2]))
		return (TRUE);
	if (any_is_crossing(tri->p[1], tri->p[2]))
		return (TRUE);
	return (FALSE);
}

static double	area(t_point p1, t_point p2, t_point p3)
{
	return (0.5 * fdf_abs((p2.x - p1.x) * (p3.y - p1.y)
			- (p3.x - p1.x) * (p2.y - p1.y)));
}

static int	in_triangle(t_tri *tri, t_point p)
{
	double	area_sub[3];
	double	area_total;
	double	eps;

	eps = 1e-6;
	area_total = area(tri->p[0], tri->p[1], tri->p[2]);
	area_sub[0] = area(tri->p[0], tri->p[1], p);
	area_sub[1] = area(tri->p[1], tri->p[2], p);
	area_sub[2] = area(tri->p[2], tri->p[0], p);
	if (area_total + eps >= area_sub[0] + area_sub[1] + area_sub[2]
		&& area_total - eps <= area_sub[0] + area_sub[1] + area_sub[2])
		return (TRUE);
	return (FALSE);
}

static int	any_in_window(t_tri *tri)
{
	if (tri->p[0].x >= 0 && tri->p[0].x < WIN_WIDTH
		&& tri->p[0].y >= 0 && tri->p[0].y < WIN_HEIGHT)
		return (TRUE);
	if (tri->p[1].x >= 0 && tri->p[1].x < WIN_WIDTH
		&& tri->p[1].y >= 0 && tri->p[1].y < WIN_HEIGHT)
		return (TRUE);
	if (tri->p[2].x >= 0 && tri->p[2].x < WIN_WIDTH
		&& tri->p[2].y >= 0 && tri->p[2].y < WIN_HEIGHT)
		return (TRUE);
	return (FALSE);
}

static int	any_is_crossing(t_point p1, t_point p2)
{
	t_point	v1;
	t_point	v2;
	t_point	v3;
	t_point	v4;

	point_init(&v1, &v2, &v3, &v4);
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

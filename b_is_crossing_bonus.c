/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_is_crossing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:25:33 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/31 13:28:22 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	is_crossing(t_point p1, t_point p2, t_point v1, t_point v2)
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

void	point_init(t_point *v1, t_point *v2, t_point *v3, t_point *v4)
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

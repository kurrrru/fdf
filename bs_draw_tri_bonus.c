/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_draw_tri_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 11:56:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:44:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static void	stl_calc_step(t_tri *tri, int *step);
static void	stl_calc_coordinate(t_point *p, t_tri *tri,
				int coeff[2], int step[2]);

void	draw_tri(t_stldata *stldata, t_tri *tri)
{
	t_point	p;
	int		step[2];
	int		i;
	int		j;

	stl_calc_step(tri, step);
	i = -1;
	while (++i <= step[0])
	{
		j = -1;
		while (++j <= step[1])
		{
			if ((double)i / step[0] + (double)j / step[1] > 1)
				continue ;
			stl_calc_coordinate(&p, tri, (int [2]){i, j}, step);
			if (i == 0 || j == 0
				|| (double)i / step[0] + (double)j / step[1] > 1 - 1e-6)
				p.color.num = STL_EDGE_COLOR;
			else
				p.color.num = STL_FACE_COLOR;
			if (stldata->endian == 1)
				small_endian_color(&p);
			stl_draw_point(stldata, p);
		}
	}
}

static void	stl_calc_step(t_tri *tri, int *step)
{
	step[0] = fdf_max(fdf_abs(tri->p[1].x - tri->p[0].x),
			fdf_abs(tri->p[1].y - tri->p[0].y)) + 1;
	step[1] = fdf_max(fdf_abs(tri->p[2].x - tri->p[0].x),
			fdf_abs(tri->p[2].y - tri->p[0].y)) + 1;
}

static void	stl_calc_coordinate(t_point *p, t_tri *tri,
	int coeff[2], int step[2])
{
	p->x = tri->p[0].x + coeff[0] * (tri->p[1].x - tri->p[0].x) / step[0]
		+ coeff[1] * (tri->p[2].x - tri->p[0].x) / step[1];
	p->y = tri->p[0].y + coeff[0] * (tri->p[1].y - tri->p[0].y) / step[0]
		+ coeff[1] * (tri->p[2].y - tri->p[0].y) / step[1];
	p->z = tri->p[0].z + coeff[0] * (tri->p[1].z - tri->p[0].z) / step[0]
		+ coeff[1] * (tri->p[2].z - tri->p[0].z) / step[1];
}

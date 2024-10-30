/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:02:20 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static void	calc_max_and_min(t_stldata *stldata);
static void	stl_shift_center(t_stldata *stldata);
static void	stl_rotate_x(t_stldata *stldata);
static void	free_stldata(t_stldata *stldata);

/*
This program only supports text-based STL files.
*/
void	stl(char *filename)
{
	t_stldata	stldata;
	int			i;

	read_stl(filename, &stldata);
	stl_rotate_x(&stldata);
	calc_max_and_min(&stldata);
	stl_size_adjust(&stldata);
	stl_shift_center(&stldata);
	stldata.mlx = mlx_init_wrap();
	stldata.win = mlx_new_window_wrap(stldata.mlx,
			WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	stldata.img = mlx_new_image_wrap(stldata.mlx, WIN_WIDTH, WIN_HEIGHT);
	stldata.addr = (int *)mlx_get_data_addr(stldata.img, &stldata.bpp,
			&stldata.size_l, &stldata.endian);
	stldata.z_buffer = (double *)malloc_wrap(sizeof(double)
			* WIN_WIDTH * WIN_HEIGHT);
	i = -1;
	while (++i < WIN_WIDTH * WIN_HEIGHT)
		stldata.z_buffer[i] = INF;
	draw_stl(&stldata);
	mlx_put_image_to_window(stldata.mlx, stldata.win, stldata.img, 0, 0);
	stl_hook(&stldata);
	mlx_loop(stldata.mlx);
	mlx_destroy_display(stldata.mlx);
	free_stldata(&stldata);
}

static void	calc_max_and_min(t_stldata *stldata)
{
	int	i;
	int	j;

	stldata->x_max = -INF;
	stldata->x_min = INF;
	stldata->y_max = -INF;
	stldata->y_min = INF;
	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			stldata->x_max = fdf_max(stldata->x_max, stldata->tris[i].p[j].x);
			stldata->x_min = fdf_min(stldata->x_min, stldata->tris[i].p[j].x);
			stldata->y_max = fdf_max(stldata->y_max, stldata->tris[i].p[j].y);
			stldata->y_min = fdf_min(stldata->y_min, stldata->tris[i].p[j].y);
		}
	}
}

static void	stl_shift_center(t_stldata *stldata)
{
	double	x_center;
	double	y_center;
	int		i;
	int		j;

	x_center = (stldata->x_max + stldata->x_min) / 2;
	y_center = (stldata->y_max + stldata->y_min) / 2;
	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			stldata->tris[i].p[j].x += WIN_WIDTH / 2 - x_center;
			stldata->tris[i].p[j].y += WIN_HEIGHT / 2 - y_center;
		}
	}
}

static void	stl_rotate_x(t_stldata *stldata)
{
	double	pos[3];
	double	angle;
	int		i;
	int		j;

	angle = -90 * PI / 180;
	i = -1;
	while (++i < stldata->tris_idx)
	{
		j = -1;
		while (++j < 3)
		{
			pos[0] = stldata->tris[i].p[j].x;
			pos[1] = stldata->tris[i].p[j].y;
			pos[2] = stldata->tris[i].p[j].z;
			rotate_x(pos, angle);
			stldata->tris[i].p[j].x = pos[0];
			stldata->tris[i].p[j].y = pos[1];
			stldata->tris[i].p[j].z = pos[2];
		}
	}
}

static void	free_stldata(t_stldata *stldata)
{
	free(stldata->tris);
	free(stldata->z_buffer);
	free(stldata->mlx);
}

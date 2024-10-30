/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 19:26:25 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

void	calc_max_and_min(t_stldata *stldata)
{
	stldata->x_max = -INF;
	stldata->x_min = INF;
	stldata->y_max = -INF;
	stldata->y_min = INF;
	for (int i = 0; i < stldata->tris_idx; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stldata->x_max = fdf_max(stldata->x_max, stldata->tris[i].p[j].x);
			stldata->x_min = fdf_min(stldata->x_min, stldata->tris[i].p[j].x);
			stldata->y_max = fdf_max(stldata->y_max, stldata->tris[i].p[j].y);
			stldata->y_min = fdf_min(stldata->y_min, stldata->tris[i].p[j].y);
		}
	}
}

void	stl_size_adjust(t_stldata *stldata)
{
	if (stldata->x_max == stldata->x_min && stldata->y_max == stldata->y_min)
		stldata->zoom = 1;
	else if (stldata->x_max == stldata->x_min)
		stldata->zoom = WIN_HEIGHT * 0.8 / (stldata->y_max - stldata->y_min);
	else if (stldata->y_max == stldata->y_min)
		stldata->zoom = WIN_WIDTH * 0.8 / (stldata->x_max - stldata->x_min);
	else
		stldata->zoom = fdf_min(WIN_WIDTH * 0.8 / (stldata->x_max - stldata->x_min),
				WIN_HEIGHT * 0.8 / (stldata->y_max - stldata->y_min));
	for (int i = 0; i < stldata->tris_idx; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stldata->tris[i].p[j].x *= stldata->zoom;
			stldata->tris[i].p[j].y *= stldata->zoom;
			stldata->tris[i].p[j].z *= stldata->zoom;
		}
	}
	stldata->x_max *= stldata->zoom;
	stldata->x_min *= stldata->zoom;
	stldata->y_max *= stldata->zoom;
	stldata->y_min *= stldata->zoom;
}

void	stl_shift_center(t_stldata *stldata)
{
	double	x_center;
	double	y_center;

	x_center = (stldata->x_max + stldata->x_min) / 2;
	y_center = (stldata->y_max + stldata->y_min) / 2;
	for (int i = 0; i < stldata->tris_idx; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			stldata->tris[i].p[j].x += WIN_WIDTH / 2 - x_center;
			stldata->tris[i].p[j].y += WIN_HEIGHT / 2 - y_center;
		}
	}
}

void	stl_rotate_x(t_stldata *stldata)
{
	double	pos[3];
	double	angle;

	angle = -90 * PI / 180;
	for (int i = 0; i < stldata->tris_idx; i++)
	{
		for (int j = 0; j < 3; j++)
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

/*
This program only supports text-based STL files.
*/
void	stl(char *filename)
{
	t_stldata	stldata;

	read_stl(filename, &stldata);
	// max, minを求める
	// trisの大きさと位置を調整。この際、頂点を表す別の要素を作成してもいい
	// 画面に表示。z-bufferを使って描画
	stl_rotate_x(&stldata);
	calc_max_and_min(&stldata);
	stl_size_adjust(&stldata);
	stl_shift_center(&stldata);


	// for (int i = 0; i < stldata.tris_idx; i++)
	// {
	// 	printf("Triangle %d\n", i);
	// 	for (int j = 0; j < 3; j++)
	// 	{
	// 		printf("  Point %d: x=%f, y=%f, z=%f\n", j, stldata.tris[i].p[j].x, stldata.tris[i].p[j].y, stldata.tris[i].p[j].z);
	// 	}
	// }
	stldata.mlx = mlx_init_wrap();
	stldata.win = mlx_new_window_wrap(stldata.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	stldata.img = mlx_new_image_wrap(stldata.mlx, WIN_WIDTH, WIN_HEIGHT);
	stldata.addr = (int *)mlx_get_data_addr(stldata.img, &stldata.bpp,
			&stldata.size_l, &stldata.endian);
	stldata.z_buffer = (double *)malloc_wrap(sizeof(double) * WIN_WIDTH * WIN_HEIGHT);
	for (int i = 0; i < WIN_WIDTH * WIN_HEIGHT; i++)
		stldata.z_buffer[i] = INF;
	printf("start drawing\n");
	draw_stl(&stldata);
	mlx_put_image_to_window(stldata.mlx, stldata.win, stldata.img, 0, 0);
	stl_hook(&stldata);
	puts("end drawing");
	mlx_loop(stldata.mlx);
	mlx_destroy_display(stldata.mlx);
	free(stldata.mlx);
	free(stldata.tris);
	free(stldata.z_buffer);
}

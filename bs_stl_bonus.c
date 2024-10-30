/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 12:16:47 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

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

	for (int i = 0; i < stldata.tris_idx; i++)
	{
		printf("Triangle %d\n", i);
		for (int j = 0; j < 3; j++)
		{
			printf("  Point %d: x=%f, y=%f, z=%f\n", j, stldata.tris[i].p[j].x, stldata.tris[i].p[j].y, stldata.tris[i].p[j].z);
		}
	}
	stldata.mlx = mlx_init_wrap();
	stldata.win = mlx_new_window_wrap(stldata.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	stldata.img = mlx_new_image_wrap(stldata.mlx, WIN_WIDTH, WIN_HEIGHT);
	stldata.addr = (int *)mlx_get_data_addr(stldata.img, &stldata.bpp,
			&stldata.size_l, &stldata.endian);
	stldata.z_buffer = (double *)malloc_wrap(sizeof(double) * WIN_WIDTH * WIN_HEIGHT);
	for (int i = 0; i < WIN_WIDTH * WIN_HEIGHT; i++)
		stldata.z_buffer[i] = INF;
	draw_stl(&stldata);
	mlx_put_image_to_window(stldata.mlx, stldata.win, stldata.img, 0, 0);
	mlx_loop(stldata.mlx);
	mlx_destroy_display(stldata.mlx);
	free(stldata.tris);
}

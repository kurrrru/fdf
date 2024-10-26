/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:00:19 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:46:40 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_map *map)
{
	t_data	data;

	data.mlx = mlx_init_wrap();
	data.win = mlx_new_window_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	data.img = mlx_new_image_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bpp,
			&data.size_l, &data.endian);
	t_point	p1 = {100, 100, {0x00FF0000}};
	t_point	p2 = {100, 200, {0x0000FF00}};
	t_point	p3 = {200, 200, {0x000000FF}};
	printf("p3: [%d, %d, %d, %d]\n", p3.color.trgb.t, p3.color.trgb.r, p3.color.trgb.g, p3.color.trgb.b);
	draw_line(&data, p1, p2);
	draw_line(&data, p2, p3);
	draw_line(&data, p3, p1);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	hook_close(&data);
	mlx_loop(data.mlx);
	(void)map;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:00:19 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 00:52:59 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf(t_map *map)
{
	t_data	data;

	printf("map summary\n");
	printf("width: %d\n", map->width);
	printf("height: %d\n", map->height);
	printf("max: %d\n", map->max);
	printf("min: %d\n", map->min);

	data.mlx = mlx_init_wrap();
	data.win = mlx_new_window_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	data.img = mlx_new_image_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bpp,
			&data.size_l, &data.endian);
	isometric(&data, map);
	printf("isometric done\n");
	draw_map(&data, map);
	printf("draw_map done\n");
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	printf("put_image_to_window done\n");
	hook_close(&data);
	mlx_loop(data.mlx);
}

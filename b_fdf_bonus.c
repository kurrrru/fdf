/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fdf_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:15 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:25:37 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

void	fdf(t_map *map)
{
	t_data	data;

	data.mlx = mlx_init_wrap();
	data.win = mlx_new_window_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	data.img = mlx_new_image_wrap(data.mlx, WIN_WIDTH, WIN_HEIGHT);
	data.addr = (int *)mlx_get_data_addr(data.img, &data.bpp,
			&data.size_l, &data.endian);
	isometric(&data, map);
	draw_map(&data, map);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	hook_close(&data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	free(data.mlx);
}

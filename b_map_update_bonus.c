/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:07:58 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:19:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

void	map_update(t_data *data, t_map *map)
{
	draw_map(data, map);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
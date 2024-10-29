/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:49:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 18:33:12 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc_wrap(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->color_flag = FALSE;
	map->data = NULL;
	map->color = NULL;
	map->points = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

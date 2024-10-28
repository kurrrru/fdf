/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:21:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:21:10 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc_wrap(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->color_flag = FALSE;
	map->data = NULL;
	map->color = NULL;
	map->z_max = INT_MIN;
	map->z_min = INT_MAX;
	return (map);
}

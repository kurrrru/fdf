/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 14:42:12 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 14:56:47 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*map_init(void)
{
	t_map	*map;

	map = (t_map *)malloc_wrap(sizeof(t_map));
	map->width = 0;
	map->height = 0;
	map->color_flag = FALSE;
	map->data = NULL;
	map->color = NULL;
	return (map);
}

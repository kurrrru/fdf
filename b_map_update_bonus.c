/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_update_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:07:58 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:21:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

void	map_update(t_data *data, t_map *map)
{
	ft_bzero(data->addr, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
	draw_map(data, map);
}

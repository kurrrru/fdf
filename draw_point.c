/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:30:35 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 21:10:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_point(t_data *data, t_point p)
{
	if (0 <= p.x && p.x < WIN_WIDTH
		&& 0 <= p.y && p.y < WIN_HEIGHT)
		data->addr[p.y * WIN_WIDTH + p.x] = p.color.num;
}

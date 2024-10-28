/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_draw_point_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:52 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:24:51 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

void	draw_point(t_data *data, t_point p)
{
	if (0 <= p.x && p.x < WIN_WIDTH
		&& 0 <= p.y && p.y < WIN_HEIGHT)
		data->addr[(int)p.y * WIN_WIDTH + (int)p.x] = p.color.num;
}

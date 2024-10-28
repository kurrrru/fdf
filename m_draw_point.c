/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_draw_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:52 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:17:53 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

void	draw_point(t_data *data, t_point p)
{
	if (0 <= p.x && p.x < WIN_WIDTH
		&& 0 <= p.y && p.y < WIN_HEIGHT)
		data->addr[(int)p.y * WIN_WIDTH + (int)p.x] = p.color.num;
}

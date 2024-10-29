/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_hook_color_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:52:07 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 19:12:28 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	hook_color(t_data *data)
{
	data->color = !data->color;
	return (0);
}

int hook_color_update(t_data *data)
{
	int	i;

	if (!data->color)
		return (0);
	i = -1;
	while (++i < WIN_HEIGHT * WIN_WIDTH)
		data->addr[i] ^= 0x00FFFFFF;
	data->color = 0;
	return (0);
}

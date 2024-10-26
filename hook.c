/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:10:32 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:15:15 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	esc_hook(int keycode, t_data *data);
static int	cross_hook(t_data *data);

void	hook_close(t_data *data)
{
	mlx_key_hook(data->win, esc_hook, data);
	mlx_hook(data->win, 17, 0, cross_hook, data);
}

static int	esc_hook(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

static int	cross_hook(t_data *data)
{
	exit(EXIT_SUCCESS);
	(void)data;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:51:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 19:03:21 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static int	stl_key_hook(int keycode, t_stldata *stldata);
static int	stl_hook_esc(t_stldata *stldata);
static int	stl_cross_hook(t_stldata *stldata);

void	stl_hook(t_stldata *stldata)
{
	mlx_key_hook(stldata->win, stl_key_hook, stldata);
	mlx_hook(stldata->win, DestroyNotify, 0, stl_cross_hook, stldata);
}

static int	stl_key_hook(int keycode, t_stldata *stldata)
{
	if (keycode == KEY_ESC)
		return (stl_hook_esc(stldata));
	return (0);
}

static int	stl_hook_esc(t_stldata *stldata)
{
	mlx_destroy_image(stldata->mlx, stldata->img);
	mlx_destroy_window(stldata->mlx, stldata->win);
	mlx_loop_end(stldata->mlx);
	stldata->win = NULL;
	return (0);
}

static int	stl_cross_hook(t_stldata *stldata)
{
	mlx_destroy_image(stldata->mlx, stldata->img);
	mlx_destroy_window(stldata->mlx, stldata->win);
	mlx_loop_end(stldata->mlx);
	stldata->win = NULL;
	return (0);
}

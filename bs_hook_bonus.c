/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:51:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:47:27 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static int	stl_key_hook(int keycode, t_stldata *stldata);
static int	stl_hook_esc(t_stldata *stldata);
static int	stl_cross_hook(t_stldata *stldata);
static int	loop_hook(t_stldata *stldata);

void	stl_hook(t_stldata *stldata)
{
	mlx_key_hook(stldata->win, stl_key_hook, stldata);
	mlx_hook(stldata->win, DestroyNotify, 0, stl_cross_hook, stldata);
	mlx_hook(stldata->win, KeyPress, KeyPressMask, stl_key_hook_loop, stldata);
	mlx_loop_hook(stldata->mlx, loop_hook, stldata);
	ft_putstr_fd(STL_USAGE, STDOUT_FILENO);
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

static int	loop_hook(t_stldata *stldata)
{
	int	i;

	if (stldata->win != NULL)
	{
		ft_bzero(stldata->addr, WIN_WIDTH * WIN_HEIGHT * sizeof(int));
		i = -1;
		while (++i < WIN_WIDTH * WIN_HEIGHT)
			stldata->z_buffer[i] = INF;
		draw_stl(stldata);
		mlx_put_image_to_window(stldata->mlx, stldata->win,
			stldata->img, 0, 0);
	}
	return (0);
}

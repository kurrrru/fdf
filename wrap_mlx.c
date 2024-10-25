/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:43:47 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/24 16:06:41 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*mlx_init_wrap(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
	return (mlx_ptr);
}

void	*mlx_new_window_wrap(void *mlx_ptr, int width, int height, char *title)
{
	void	*win_ptr;

	win_ptr = mlx_new_window(mlx_ptr, width, height, title);
	if (win_ptr == NULL)
	{
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
	return (win_ptr);
}

void	*mlx_new_image_wrap(void *mlx_ptr, int width, int height)
{
	void	*img_ptr;

	img_ptr = mlx_new_image(mlx_ptr, width, height);
	if (img_ptr == NULL)
	{
		perror("mlx_new_image");
		exit(EXIT_FAILURE);
	}
	return (img_ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_xd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:01:28 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 14:42:05 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_3d(char ***p)
{
	int	i;
	int	j;

	i = -1;
	while (p[++i] != NULL)
	{
		j = -1;
		while (p[i][++j] != NULL)
			free(p[i][j]);
		free(p[i]);
	}
	free(p);
}

void	free_map(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->height)
	{
		free(map->data[i]);
		free(map->color[i]);
	}
	free(map->data);
	free(map->color);
	free(map);
}

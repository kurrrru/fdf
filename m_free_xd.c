/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_free_xd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:19:50 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:19:50 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

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
		free(map->points[i]);
	}
	free(map->data);
	free(map->color);
	free(map->points);
	free(map);
}

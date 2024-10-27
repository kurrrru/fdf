/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:53:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:05 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "include.h"
# include "point.h"

typedef struct s_map
{
	int		**data;
	int		**color;
	int		height;
	int		width;
	int		color_flag;
	int		z_max;
	int		z_min;
	t_point	**points;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_map;

// map_init.c
t_map	*map_init(void);

# endif

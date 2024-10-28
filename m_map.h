/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_map.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:21:24 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:27:19 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_MAP_H
# define M_MAP_H

# include "m_include.h"
# include "m_point.h"

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

// m_map_init.c
t_map	*map_init(void);

#endif

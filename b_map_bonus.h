/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:02:08 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 23:15:30 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_MAP_BONUS_H
# define B_MAP_BONUS_H

# include "b_include_bonus.h"
# include "b_point_bonus.h"

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

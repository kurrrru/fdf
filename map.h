/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:53:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 19:59:31 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "include.h"

typedef struct s_map
{
	int	**data;
	int	**color;
	int	height;
	int	width;
	int	color_flag;
}	t_map;

// map_init.c
t_map	*map_init(void);

# endif

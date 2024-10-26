/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:54 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:48:05 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef struct	s_trgb
{
	unsigned int	t : 8;
	unsigned int	r : 8;
	unsigned int	g : 8;
	unsigned int	b : 8;
}	t_trgb;

typedef union	u_color
{
	int		color_int;
	t_trgb	trgb;
}	t_color;

typedef struct	s_point
{
	int		x;
	int		y;
	t_color	color;
}	t_point;

#endif
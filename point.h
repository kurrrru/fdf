/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:54:54 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 18:38:36 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

typedef union	u_color
{
	unsigned int	num;
	unsigned char	trgb[4];
}	t_color;

typedef struct	s_point
{
	int		x;
	int		y;
	t_color	color;
}	t_point;

#endif
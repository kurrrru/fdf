/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_point.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:02 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:22:02 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_POINT_H
# define M_POINT_H

typedef union u_color
{
	unsigned int	num;
	unsigned char	trgb[4];
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	t_color	color;
}	t_point;

#endif

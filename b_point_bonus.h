/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_point_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 23:03:52 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:01:18 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_POINT_BONUS_H
# define B_POINT_BONUS_H

typedef union u_color
{
	unsigned int	num;
	unsigned char	trgb[4];
}	t_color;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	t_color	color;
}	t_point;

#endif

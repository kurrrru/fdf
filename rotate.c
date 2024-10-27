/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:54:58 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 14:57:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double pos[3], double angle)
{
	matrix_multiply(pos, (double [3][3]){
	{1, 0, 0},
	{0, cos(angle), -sin(angle)},
	{0, sin(angle), cos(angle)}
	});
}

void	rotate_y(double pos[3], double angle)
{
	matrix_multiply(pos, (double [3][3]){
	{cos(angle), 0, sin(angle)},
	{0, 1, 0},
	{-sin(angle), 0, cos(angle)}
	});
}

void	rotate_z(double pos[3], double angle)
{
	matrix_multiply(pos, (double [3][3]){
	{cos(angle), -sin(angle), 0},
	{sin(angle), cos(angle), 0},
	{0, 0, 1}
	});
}

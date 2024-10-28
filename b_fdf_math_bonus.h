/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fdf_math_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:52 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 20:57:23 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_FDF_MATH_BONUS_H
# define B_FDF_MATH_BONUS_H

int		fdf_abs(int n);
int		fdf_max(int a, int b);
int		fdf_min(int a, int b);
int		in_div(int p1, int p2, int i, int total);

double	fdf_abs_d(double n);
double	fdf_max_d(double a, double b);
double	fdf_min_d(double a, double b);
double	in_div_d(double p1, double p2, int i, int total);

void	matrix_multiply(double pos[3], double matrix[3][3]);

#endif

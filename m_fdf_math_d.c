/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fdf_math_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:18:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf_math.h"

double	fdf_abs_d(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}

double	fdf_max_d(double a, double b)
{
	if (a > b)
		return (a);
	return (b);
}

double	fdf_min_d(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

double	in_div_d(double p1, double p2, int i, int total)
{
	if (total == 0)
		return (p1);
	return (p1 + (p2 - p1) * i / total);
}

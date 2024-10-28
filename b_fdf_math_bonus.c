/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_fdf_math_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:42 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:26:01 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_math_bonus.h"

int	fdf_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	fdf_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	fdf_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	in_div(int p1, int p2, int i, int total)
{
	if (total == 0)
		return (p1);
	return (p1 + (p2 - p1) * i / total);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:18:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:34:51 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_math.h"

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

int	fdf_in_div(int p1, int p2, int i, int total)
{
	return (p1 + (p2 - p1) * i / total);
}

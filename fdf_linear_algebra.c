/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_linear_algebra.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:53:23 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 14:53:45 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_math.h"

void	matrix_multiply(double pos[3], double matrix[3][3])
{
	double	tmp[3];
	int		i;
	int		j;

	i = -1;
	while (++i < 3)
	{
		tmp[i] = 0;
		j = -1;
		while (++j < 3)
			tmp[i] += pos[j] * matrix[j][i];
	}
	i = -1;
	while (++i < 3)
		pos[i] = tmp[i];
}

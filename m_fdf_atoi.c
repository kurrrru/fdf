/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fdf_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:04 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:18:04 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

void	fdf_atoi(const char *str, t_map *map, int i, int j)
{
	long	ret;
	long	sign;

	ret = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0') * sign;
	map->data[i][j] = (int)ret;
	map->z_max = fdf_max(map->z_max, map->data[i][j]);
	map->z_min = fdf_min(map->z_min, map->data[i][j]);
	if (*str++ == ',')
		fdf_atox(str, map, i, j);
}
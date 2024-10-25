/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:07:25 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 19:07:25 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	if (*str++ == ',')
		fdf_atox(str, map, i, j);
}

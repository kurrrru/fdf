/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fdf_atox.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:18:14 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:18:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

void	fdf_atox(const char *str, t_map *map, int i, int j)
{
	int			num;

	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	str += 2;
	num = 0;
	while (ft_isdigit(*str) || ('a' <= *str && *str <= 'f')
		|| ('A' <= *str && *str <= 'F'))
	{
		if (ft_isdigit(*str))
			num = num * 16 + *str++ - '0';
		else if ('a' <= *str && *str <= 'f')
			num = num * 16 + *str++ - 'a' + 10;
		else
			num = num * 16 + *str++ - 'A' + 10;
	}
	map->color_flag = TRUE;
	map->color[i][j] = num;
}

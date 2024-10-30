/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_draw_stl_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:14:18 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 12:14:45 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

void	draw_stl(t_stldata *stldata)
{
	int	i;

	i = -1;
	while (++i < stldata->tris_idx)
		draw_tri(stldata, &stldata->tris[i]);
}

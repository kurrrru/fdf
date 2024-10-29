/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 01:46:34 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

/*
This program only supports text-based STL files.
*/
void	stl(char *filename)
{
	t_stldata	stldata;

	read_stl(filename, &stldata);
	// max, minを求める
	// trisの大きさと位置を調整。この際、頂点を表す別の要素を作成してもいい
	// 画面に表示。z-bufferを使って描画

	for (int i = 0; i < stldata.tris_idx; i++)
	{
		printf("Triangle %d\n", i);
		for (int j = 0; j < 3; j++)
		{
			printf("  Point %d: x=%f, y=%f, z=%f\n", j, stldata.tris[i].p[j].x, stldata.tris[i].p[j].y, stldata.tris[i].p[j].z);
		}
	}
	free(stldata.tris);
}

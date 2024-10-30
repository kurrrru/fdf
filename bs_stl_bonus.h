/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:07:12 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BS_STL_BONUS_H
# define BS_STL_BONUS_H

# include "b_fdf_bonus.h"

# define STL_EDGE_COLOR	0x000000FF
# define STL_FACE_COLOR	0x00FFFFFF

typedef struct s_tri
{
	t_point		p[3];
}	t_tri;

typedef struct s_stldata
{
	void		*mlx;
	void		*win;
	void		*img;
	int			*addr;
	int			bpp;
	int			size_l;
	int			endian;
	double		zoom;
	double		rotate_x;
	double		rotate_y;
	double		rotate_z;
	t_tri		*tris;
	int			tris_idx;
	int			tris_len;
	double		*z_buffer;
	double		z_max;
	double		z_min;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
}	t_stldata;

void	stl(char *filename);

void	read_stl(char *filename, t_stldata *stldata);

void	draw_tri(t_stldata *stldata, t_tri *tri);

void	stl_draw_point(t_stldata *stldata, t_point p);

void	draw_stl(t_stldata *stldata);

void	stl_hook(t_stldata *stldata);

void	stl_size_adjust(t_stldata *stldata);

#endif
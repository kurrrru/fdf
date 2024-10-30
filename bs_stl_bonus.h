/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 21:36:56 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BS_STL_BONUS_H
# define BS_STL_BONUS_H

# include "b_fdf_bonus.h"

# define STL_EDGE_COLOR	0x000000FF
# define STL_FACE_COLOR	0x00FFFFFF

# define STL_USAGE "[Usage]\n\
Zoom in/out: m/n\n\
Move: arrow keys\n\
Rotate x-axis: q/w\n\
Rotate y-axis: a/s\n\
Rotate z-axis: z/x\n\
Exit: ESC\n"

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

// bs_stl_bonus.c
void	stl(char *filename);

// bs_read_bonus.c
void	read_stl(char *filename, t_stldata *stldata);

// bs_draw_tri_bonus.c
void	draw_tri(t_stldata *stldata, t_tri *tri);

// bs_draw_point_bonus.c
void	stl_draw_point(t_stldata *stldata, t_point p);

// bs_draw_stl_bonus.c
void	draw_stl(t_stldata *stldata);

// bs_hook_bonus.c
void	stl_hook(t_stldata *stldata);

// bs_hook_bonus.c
void	stl_size_adjust(t_stldata *stldata);

// bs_hook_rotate_bonus.c
int		stl_hook_rotate_x(t_stldata *stldata, int keycode);
int		stl_hook_rotate_y(t_stldata *stldata, int keycode);
int		stl_hook_rotate_z(t_stldata *stldata, int keycode);

// bs_hook_zoom_bonus.c
int		stl_hook_zoom(t_stldata *stldata, int keycode);

// bs_hook_move_bonus.c
int		stl_hook_move(t_stldata *stldata, int keycode);

// bs_key_hook_loop_bonus.c
int		stl_key_hook_loop(int keycode, t_stldata *stldata);

#endif
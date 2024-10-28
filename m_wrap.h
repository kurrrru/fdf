/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_wrap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:27:41 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_WRAP_H
# define M_WRAP_H

# include "m_include.h"

// m_wrap_file_manip.c
int		open_wrap(char *filename, int flags);
void	close_wrap(int fd);

// m_wrap_memory.c
void	*malloc_wrap(size_t size);
void	*realloc_wrap(void *ptr, size_t old_size, size_t new_size);
char	**ft_split_wrap(char const *s, char c);

// m_wrap_mlx.c
void	*mlx_init_wrap(void);
void	*mlx_new_window_wrap(void *mlx_ptr, int width,
			int height, char *title);
void	*mlx_new_image_wrap(void *mlx_ptr, int width, int height);

#endif

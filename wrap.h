/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:56:31 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 19:57:16 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRAP_H
# define WRAP_H

# include "include.h"

// wrap_file_manip.c
int		open_wrap(char *filename, int flags);
void	close_wrap(int fd);

// wrap_memory.c
void	*malloc_wrap(size_t size);
void	*realloc_wrap(void *ptr, size_t old_size, size_t new_size);
char	**ft_split_wrap(char const *s, char c);

// wrap_mlx.c
void	*mlx_init_wrap(void);
void	*mlx_new_window_wrap(void *mlx_ptr, int width,
			int height, char *title);
void	*mlx_new_image_wrap(void *mlx_ptr, int width, int height);

#endif

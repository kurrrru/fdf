/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_wrap_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:53 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:38:08 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_WRAP_BONUS_H
# define B_WRAP_BONUS_H

# include "b_include_bonus.h"

// b_wrap_file_manip_bonus.c
int		open_wrap(char *filename, int flags);
void	close_wrap(int fd);

// b_wrap_memory_bonus.c
void	*malloc_wrap(size_t size);
void	*realloc_wrap(void *ptr, size_t old_size, size_t new_size);
char	**ft_split_wrap(char const *s, char c);

// b_wrap_mlx_bonus.c
void	*mlx_init_wrap(void);
void	*mlx_new_window_wrap(void *mlx_ptr, int width,
			int height, char *title);
void	*mlx_new_image_wrap(void *mlx_ptr, int width, int height);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:24:29 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/09 20:56:31 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAILURE -1

# define PROPER_ARGC 2
# define MSG_USAGE "Usage Error: ./fdf [*.fdf]"

# define PROPER_EXTENSION ".fdf"
# define PROPER_EXTENSION_LEN 4
# define MSG_EXTENSION_ERROR "Extension Error: The extension of the file must be \".fdf\""

void	error_usage(void);
void	error_extension(void);
int		is_valid_extension(char *filename);

#endif

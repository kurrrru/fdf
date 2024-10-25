/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_file_manip.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:49:27 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/24 15:52:11 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	open_wrap(char *filename, int flags)
{
	int	fd;

	fd = open(filename, flags);
	if (fd == ERROR)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	close_wrap(int fd)
{
	if (close(fd) == ERROR)
	{
		perror("close");
		exit(EXIT_FAILURE);
	}
}

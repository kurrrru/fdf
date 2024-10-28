/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_wrap_file_manip_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 00:50:49 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_wrap_bonus.h"

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

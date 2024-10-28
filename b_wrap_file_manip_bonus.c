/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_wrap_file_manip.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:22:26 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:22:27 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_wrap.h"

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

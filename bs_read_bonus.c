/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_read_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 01:08:12 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/30 01:43:54 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

static int	split_len(char **split);
static int	read_triangle(int fd, t_stldata *stldata);
static void	error_exit(char *message);
static void	convert_to_triangle(t_stldata *stldata, char **splited, int i);

void	read_stl(char *filename, t_stldata *stldata)
{
	int		fd;

	fd = open_wrap(filename, O_RDONLY);
	free(get_next_line(fd));
	stldata->tris_idx = 0;
	stldata->tris_len = 1;
	stldata->tris = (t_tri *)malloc(sizeof(t_tri) * stldata->tris_len);
	while (TRUE)
	{
		if (read_triangle(fd, stldata) == FALSE)
			break ;
		stldata->tris_idx++;
		if (stldata->tris_idx >= stldata->tris_len)
		{
			stldata->tris_len *= 2;
			stldata->tris = (t_tri *)realloc_wrap(stldata->tris, sizeof(t_tri)
					* stldata->tris_idx, sizeof(t_tri) * stldata->tris_len);
		}
	}
	close_wrap(fd);
}

static int	read_triangle(int fd, t_stldata *stldata)
{
	char	*line;
	char	**split;
	int		i;

	i = -1;
	free(get_next_line(fd));
	free(get_next_line(fd));
	while (++i < 3)
	{
		line = get_next_line(fd);
		if (line == NULL && i == 0)
			return (FALSE);
		if (line == NULL)
			error_exit("Invalid STL file");
		split = ft_split_wrap(line, ' ');
		if (split_len(split) != 4)
			error_exit("Invalid STL file");
		convert_to_triangle(stldata, split, i);
		free_2d(split);
		free(line);
	}
	free(get_next_line(fd));
	free(get_next_line(fd));
	return (TRUE);
}

static int	split_len(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
		i++;
	return (i);
}

static void	error_exit(char *message)
{
	ft_putendl_fd(message, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	convert_to_triangle(t_stldata *stldata, char **splited, int i)
{
	stldata->tris[stldata->tris_idx].p[i].x = atof(splited[1]);
	stldata->tris[stldata->tris_idx].p[i].y = atof(splited[2]);
	stldata->tris[stldata->tris_idx].p[i].z = atof(splited[3]);
}

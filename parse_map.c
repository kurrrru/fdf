/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:53:48 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/26 20:03:57 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	read_map(int fd, char ****map_str, int *map_size);
static void	size_check(char ***map_str, t_map *map);

void	parse_file(char *filename, t_map *map)
{
	int		fd;
	char	***map_str;
	int		map_size;
	int		i;
	int		j;

	fd = open_wrap(filename, O_RDONLY);
	read_map(fd, &map_str, &map_size);
	size_check(map_str, map);
	map->data = (int **)malloc_wrap(sizeof(int *) * map->height);
	map->color = (int **)malloc_wrap(sizeof(int *) * map->height);
	i = -1;
	while (map_str[++i] != NULL)
	{
		map->data[i] = (int *)malloc_wrap(sizeof(int) * map->width);
		map->color[i] = (int *)malloc_wrap(sizeof(int) * map->width);
		j = -1;
		while (map_str[i][++j] != NULL)
		{
			atoi_check(map_str[i][j], map);
			fdf_atoi(map_str[i][j], map, i, j);
		}
	}
	free_3d(map_str);
	close_wrap(fd);
}

static void	read_map(int fd, char ****map_str, int *map_size)
{
	char	*line;
	int		i;

	i = -1;
	*map_size = 1;
	*map_str = (char ***)malloc_wrap(sizeof(char **) * *map_size);
	while (TRUE)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = ' ';
		(*map_str)[++i] = ft_split_wrap(line, ' ');
		free(line);
		if (i == *map_size - 1)
		{
			*map_size *= 2;
			*map_str = (char ***)realloc_wrap(*map_str, sizeof(char **)
					* (i + 1), sizeof(char **) * *map_size);
		}
	}
}

static void	size_check(char ***map_str, t_map *map)
{
	int	i;
	int	j;

	map->width = 0;
	i = -1;
	while (map_str[++i])
	{
		j = 0;
		while (map_str[i][j])
			j++;
		if (j == 0)
		{
			ft_putendl_fd(MSG_MAP_EMPTY, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		else if (map->width == 0)
			map->width = j;
		else if (map->width != j)
		{
			ft_putendl_fd(MSG_WIDTH_NOT_EQUAL, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
	}
	map->height = i;
}

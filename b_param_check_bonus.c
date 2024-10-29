/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_param_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 00:49:51 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:03:53 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

static int	is_valid_extension(char *filename);
static void	error_usage(void);
static void	error_extension(void);

int	param_check(int argc, char **argv)
{
	int	ret;

	if (argc != PROPER_ARGC)
		error_usage();
	ret = is_valid_extension(argv[1]);
	if (ret == FALSE)
		error_extension();
	return (ret);
}

static int	is_valid_extension(char *filename)
{
	int		len;
	char	*suffix;

	len = ft_strlen(filename);
	if (len < PROPER_EXTENSION_LEN)
		return (FALSE);
	suffix = filename + len - PROPER_EXTENSION_LEN;
	if (ft_strncmp(suffix, PROPER_EXTENSION, PROPER_EXTENSION_LEN) == 0)
		return (TRUE);
	if (ft_strncmp(suffix, STL_FILE_EXTENSION, STL_FILE_EXTENSION_LEN) == 0)
		return (STL_FLAG);
	return (FALSE);
}

static void	error_usage(void)
{
	ft_putendl_fd(MSG_USAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	error_extension(void)
{
	ft_putendl_fd(MSG_EXTENSION_ERROR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

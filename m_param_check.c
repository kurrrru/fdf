/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_param_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:21:41 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/28 12:21:41 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_fdf.h"

static int	is_valid_extension(char *filename);
static void	error_usage(void);
static void	error_extension(void);

void	param_check(int argc, char **argv)
{
	if (argc != PROPER_ARGC)
		error_usage();
	if (!is_valid_extension(argv[1]))
		error_extension();
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

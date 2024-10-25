/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atox_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:40:03 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 14:38:32 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error_atox_check(char *str);
static void	space_skip(const char *str, int *i);

void	atox_check(const char *str, int i)
{
	int			num;

	space_skip(str, &i);
	if (str[i] != '0' || (str[i + 1] != 'x' && str[i + 1] != 'X'))
		error_atox_check(MSG_ATOX_ERROR_PREFIX);
	i += 2;
	num = 0;
	while (ft_isdigit(str[i]) || ('a' <= str[i] && str[i] <= 'f')
		|| ('A' <= str[i] && str[i] <= 'F'))
	{
		if (ft_isdigit(str[i]))
			num = num * 16 + str[i++] - '0';
		else if ('a' <= str[i] && str[i] <= 'f')
			num = num * 16 + str[i++] - 'a' + 10;
		else
			num = num * 16 + str[i++] - 'A' + 10;
		if (num > COLOR_MAX)
			error_atox_check(MSG_ATOX_ERROR_LARGE);
	}
	if (str[i] != '\0')
		error_atox_check(MSG_ATOX_ERROR_NOT_HEX);
}

static void	error_atox_check(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	space_skip(const char *str, int *i)
{
	while ((9 <= str[*i] && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
}

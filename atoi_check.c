/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:34:10 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/27 00:29:53 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	space_sign_skip(const char *str, int *i, long *sign);
static void	error_atoi_check(char *str);

void	atoi_check(const char *str, t_map *map)
{
	int		i;
	long	sign;
	long	num;

	space_sign_skip(str, &i, &sign);
	if (!ft_isdigit(str[i]))
		error_atoi_check(MSG_ATOI_ERROR_PREFIX_NOT_DIGIT);
	num = 0;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i++] - '0') * sign;
		if (num > INT_MAX)
			error_atoi_check(MSG_ATOI_ERROR_LARGE);
		else if (num < INT_MIN)
			error_atoi_check(MSG_ATOI_ERROR_SMALL);
	}
	if (str[i] == ',')
	{
		map->color_flag = TRUE;
		atox_check(str, ++i);
	}
	else if (str[i] != '\0')
		error_atoi_check(MSG_ATOI_ERROR_NOT_DIGIT);
}

static void	error_atoi_check(char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

static void	space_sign_skip(const char *str, int *i, long *sign)
{
	*i = 0;
	while ((9 <= str[*i] && str[*i] <= 13) || str[*i] == ' ')
		(*i)++;
	*sign = 1;
	if (str[*i] == '+' || str[*i] == '-')
		if (str[(*i)++] == '-')
			*sign = -1;
}

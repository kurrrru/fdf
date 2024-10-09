/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_usage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:27:08 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/09 20:33:39 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_usage(void)
{
	ft_putendl_fd(PROPER_USAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

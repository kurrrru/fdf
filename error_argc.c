/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:27:08 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/09 20:51:43 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_usage(void)
{
	ft_putendl_fd(MSG_USAGE, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:46:13 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/09 20:49:46 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_extension(void)
{
	ft_putendl_fd(MSG_EXTENSION_ERROR, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

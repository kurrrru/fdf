/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bs_stl_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 23:05:38 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:23:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bs_stl_bonus.h"

/*
This program only supports text-based STL files.
*/
void	stl(char *filename)
{
	(void)filename;
	ft_putstr_fd(filename, STDERR_FILENO);
}

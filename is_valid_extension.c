/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:36:13 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/09 20:51:14 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_valid_extension(char *filename)
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
